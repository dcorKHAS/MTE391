#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>


Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane)
    : position(glm::vec3(0.0f, 0.0f, 3.0f)),
    worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
    yaw(-90.0f),
    pitch(0.0f),
    fov(fov),
    speed(20.0f),
    rotationSpeed(250.0f),
    aspectRatio(aspectRatio),
    nearPlane(nearPlane),
    farPlane(farPlane){
    updateCameraVectors();
}

void Camera::SetPosition(const glm::vec3& position) {
    this->position = position;
    updateCameraVectors();
}

void Camera::SetOrientation(float pitch, float yaw) {
    this->pitch = pitch;
    this->yaw = yaw;
    updateCameraVectors();
}

void Camera::Move(const glm::vec3& offset) {
    position += offset;
    updateCameraVectors();
}

void Camera::Rotate(float pitchOffset, float yawOffset) {
    pitch += pitchOffset;
    yaw += yawOffset;

    // Clamping the pitch value to prevent flipping
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::GetProjectionMatrix() const {
    return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
}

void Camera::updateCameraVectors() {
    // Calculate the new Front vector
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);

    // Recalculate the Right and Up vector
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}

void Camera::HandleKeyInput(SDL_Keycode key, float deltaTime) {
    // Movement
    glm::vec3 direction;
    bool isMoving = true;
    switch (key) {
    case SDLK_w:
        direction = front;
        break;
    case SDLK_s:
        direction = -front;
        break;
    case SDLK_a:
        direction = -right;
        break;
    case SDLK_d:
        direction = right;
        break;
    default:
        isMoving = false;
        break;
    }

    if (isMoving) {
       Move( direction * speed * deltaTime);
        return;
    }

    // Rotation
    
    switch (key) {
    case SDLK_e:
        Rotate(0.0f, rotationSpeed * deltaTime);
        break;
    case SDLK_q:
        Rotate(0.0f, -rotationSpeed * deltaTime);
        break;
        // Add more cases for other rotation keys if needed
    }
}
