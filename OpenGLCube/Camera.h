#pragma once
#include <glm/glm.hpp>
#include <SDL.h>


class Camera {
public:
    Camera(float fov, float aspectRatio, float nearPlane, float farPlane);

    void UpdateCameraPosition(float deltaTime);
    void UpdateCameraDirection(float pitch, float yaw);

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix() const;

    void SetPosition(const glm::vec3& position);
    void SetOrientation(float pitch, float yaw);
    
    void Move(const glm::vec3& offset);
    void Rotate(float pitchOffset, float yawOffset);


    //getters
    glm::vec3 GetPosition() const { return position; }
    glm::vec3 GetFront() const { return front; }
    glm::vec3 GetUp() const { return up; }
    glm::vec3 GetRight() const { return right; }
    glm::vec3 GetWorldUp() const { return worldUp; }
    float GetFov() const { return fov; }
    float GetAspectRatio() const { return aspectRatio; }
    float GetNearPlane() const { return nearPlane; }
    float GetFarPlane() const { return farPlane; }
    float GetYaw() const { return yaw; }
    float GetPitch() const { return pitch; }
    void HandleKeyInput(SDL_Keycode key, float deltaTime);
    

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;

    float yaw;
    float pitch;

    float speed;
    float rotationSpeed;

    void updateCameraVectors();

};


