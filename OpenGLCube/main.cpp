#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "ShaderManager.h"
#include "Vertex.h"
#include "SDLHandler.h"
#include "Camera.h"
#include "BufferManager.h"
#include "Transform.h"



// Vertex Shader source code
const GLchar* vertexShaderSource = R"glsl(
   #version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vertexColor;

out vec3 fragmentColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {
    gl_Position =     gl_Position = projection * view * model * vec4(position, 1.0f);

    fragmentColor = vertexColor;
}

)glsl";

// Fragment Shader source code
const GLchar* fragmentShaderSource = R"glsl(
   #version 330 core
out vec4 color;

in vec3 fragmentColor;

void main() {
    color = vec4(fragmentColor, 1.0f);
}

)glsl";

int main(int argc, char* argv[]) {
    
    //Window dimensions
    
    const GLuint WIDTH = 800, HEIGHT = 600;

    //Create a new SDLHandler from heap
    
    SDLHandler* sdlHandler = new SDLHandler(WIDTH, HEIGHT);
    
    //Create a new shader manager from heap

    ShaderManager* shaderManager = new ShaderManager(vertexShaderSource, fragmentShaderSource);
    
    //Create a new buffer manager from heap
    BufferManager* bufferManager = new BufferManager();
    
    
    //Create vertices and indices for the cube
    std::vector<Vertex> vertices = {
     {{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}}, // Bottom-left-back - Red
     {{ 0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}}, // Bottom-right-back - Green
     {{ 0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}}, // Top-right-back - Blue
     {{-0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 0.0f}}, // Top-left-back - Yellow
     {{-0.5f, -0.5f,  0.5f}, {1.0f, 0.0f, 1.0f}}, // Bottom-left-front - Magenta
     {{ 0.5f, -0.5f,  0.5f}, {0.0f, 1.0f, 1.0f}}, // Bottom-right-front - Cyan
     {{ 0.5f,  0.5f,  0.5f}, {0.5f, 0.5f, 0.5f}}, // Top-right-front - Grey
     {{-0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}}  // Top-left-front - White
    };

    std::vector<GLuint> indices = {
        0, 1, 2, 2, 3, 0,  // Front face
        1, 5, 6, 6, 2, 1,  // Right face
        7, 6, 5, 5, 4, 7,  // Back face
        4, 0, 3, 3, 7, 4,  // Left face
        4, 5, 1, 1, 0, 4,  // Bottom face
        3, 2, 6, 6, 7, 3   // Top face
    };

    //Setup buffers with EBO
    bufferManager->SetupBuffersWithEBO(vertices, indices);

    //Create new Transform from heap
    Transform* transform = new Transform();

    //Create new camera from heap

    float aspectRatio = static_cast<float>(sdlHandler->getWidth()) / static_cast<float>(sdlHandler->getHeight());
    Camera * camera=new Camera (45.0f, aspectRatio, 0.1f, 100.0f);
    camera->SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));
    
    //We can activate shader program and get uniform locations here since we only have one shader program
    shaderManager->run();
    GLuint shaderProgram = shaderManager->getProgramId();
    GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLuint viewLoc = glGetUniformLocation(shaderProgram, "view");
    GLuint projLoc = glGetUniformLocation(shaderProgram, "projection");
    
    
    //Last frame time in seconds initialized to 0
    float lastFrame = 0.0f;

    //Loop
    bool running = true;
    while (running) {
        // Calculate delta time
        float currentFrame = SDL_GetTicks() / 1000.0f;
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;


        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN) {
               
                switch (event.key.keysym.sym) {
                
                 //Camera controls   
                 //wasd for moving the camera
                    case SDLK_w:  case SDLK_s:  case SDLK_a:  case SDLK_d:
                //q,e for tilting the camera left and right
                    case SDLK_q:  case SDLK_e:
                    
                        camera->HandleKeyInput(event.key.keysym.sym, deltaTime);
                        break;
                
                //Object controls
                //arrow keys for moving the object
                    case SDLK_UP:   case SDLK_DOWN:     case SDLK_LEFT:    case SDLK_RIGHT:
                //t,y,u,i,o,p for rotating the object
                    case SDLK_t:    case SDLK_y:   case SDLK_u:    case SDLK_i:   case SDLK_o:   case SDLK_p: 
                    
                    transform->HandleKeyInput(event.key.keysym.sym);
                    break;
                }
            }

        }
        glm::mat4 view = camera->GetViewMatrix();
        glm::mat4 projection = camera->GetProjectionMatrix();
        const glm::mat4& modelMatrix = transform->GetModelMatrix();
        //Render
        
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            
        //Clear the color buffer
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Draw the object
        bufferManager->BindVAO();
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // Swap the screen buffers
        sdlHandler->swap();
    }

    // Properly de-allocate all resources once they've outlived their purpose
       
        delete bufferManager;
        delete shaderManager;
        delete sdlHandler;
        delete transform;
        delete camera;

        return 0;
    }
