#include "SDLHandler.h"
#include <SDL.h>
#include <GL/glew.h>
#include <iostream>


SDLHandler::SDLHandler(GLuint width, GLuint height) : width(width), height(height), window(NULL), glContext(NULL)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
      
    }

    // Use OpenGL 3.3 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


    // Create window
    window = SDL_CreateWindow("3D Cube", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    
    }

    // Create OpenGL context
    glContext = SDL_GL_CreateContext(window);
    if (glContext == NULL) {
        std::cout << "OpenGL context could not be created! SDL_Error: " << SDL_GetError() << std::endl;

    }

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        
    }
    glEnable(GL_DEPTH_TEST);


    // Define the viewport dimensions
    glViewport(0, 0, width, height);

    //Create a new shader manager from heap
}

void SDLHandler::swap()
{
    SDL_GL_SwapWindow(window);
}

//destructor
SDLHandler::~SDLHandler()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//getters
SDL_Window* SDLHandler::getWindow()
{
	return window;
}

SDL_GLContext SDLHandler::getGLContext()
{
	return glContext;
}

GLuint SDLHandler::getWidth()
{
	return width;
}

GLuint SDLHandler::getHeight()
{
	return height;
}

