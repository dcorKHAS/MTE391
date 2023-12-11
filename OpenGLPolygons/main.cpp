#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderManager.h"
#include "BufferManager.h"
#include "Vertex.h"
#include "SDLmanager.h"
#include "Transform.h"
// Vertex Shader source code
const GLchar* vertexSource = R"ANYTHING(
   #version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform vec3 offset; // Uniform variable for position offset

out vec3 Color;

void main() {
    Color = color;
    gl_Position = vec4(position + offset, 1.0); // Apply the offset to the position
}
)ANYTHING";

// Fragment Shader source code
const GLchar* fragmentSource = R"glsl(
    #version 330 core
    in vec3 Color;
    out vec4 outColor;

    void main() {
        outColor = vec4(Color, 1.0);
    }
)glsl";

int main(int argc, char* argv[]) {
  
    Vertex vertices[] = {

    Vertex(glm::vec3(-0.5f, -0.5f, 0.0f) , glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(0.0f,  0.5f, 0.0f) , glm::vec3(0.0f, 0.0f, 1.0f)),
    };
   
    SDLManager* sdlManager = new SDLManager();

    //Create a new shader manager from the heap
    ShaderManager* myShader = new ShaderManager(vertexSource, fragmentSource);
    
    myShader->run();

    BufferManager* triangleBuffer = new BufferManager(vertices, 3);

    // Main loop
    glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f);
    float speed = 0.01f; // Movement speed
    bool running = true;
    while (running) {
       
        sdlManager->handleEvents(&running, &offset, speed);
        
        // Clear the screen
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle
        
        GLint offsetLocation = glGetUniformLocation(myShader->getProgramId(), "offset");
        glUniform3f(offsetLocation, offset.x, offset.y, offset.z);
        triangleBuffer->BindVAO();
       // glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        // Swap buffers
        sdlManager->swap();

    }

    // Clean up
  
    delete myShader;

    delete triangleBuffer;

    delete sdlManager;

    return 0;
}
