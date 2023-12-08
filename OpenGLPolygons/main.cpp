#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderManager.h"
#include "BufferManager.h"
#include "Vertex.h"
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
  
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Set OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("OpenGL Triangle", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create OpenGL context
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (context == nullptr) {
        std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "glewInit Error" << std::endl;
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //Create a new shader manager from the heap
    ShaderManager* myShader = new ShaderManager(vertexSource, fragmentSource);
    
    myShader->run();

    // Define vertices for a triangle
    //float vertices[] = {
    //    // Position         // Color
    //    -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Bottom-left, red
    //     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom-right, green
    //     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Top, blue
    //};

    Vertex vertices[] = {

       Vertex(glm::vec3(-0.5f, -0.5f, 0.0f) , glm::vec3(1.0f, 0.0f, 0.0f)),
       Vertex(glm::vec3(0.5f, -0.5f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)),
       Vertex(glm::vec3(0.0f,  0.5f, 0.0f) , glm::vec3(0.0f, 0.0f, 1.0f)),




    };

   BufferManager* triangleBuffer = new BufferManager(vertices, 3);


    
    //// Create VBO(Vertex buffer object) and VAO (Vertex Array object)
    //GLuint VBO, VAO;
    //glGenVertexArrays(1, &VAO);
    //glGenBuffers(1, &VBO);

    //glBindVertexArray(VAO);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//To check

    //// Position attribute
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    //// Color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
    
    // Main loop
    glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f);
    float speed = 0.01f; // Movement speed
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_w: offset.y += speed; break;
                case SDLK_s: offset.y -= speed; break;
                case SDLK_a: offset.x -= speed; break;
                case SDLK_d: offset.x += speed; break;
                }
            }
        }
      
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
        SDL_GL_SwapWindow(window);
    }

    // Clean up
  
    delete myShader;

    delete triangleBuffer;

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
