#pragma once
#include <SDL.h>
#include <GL/glew.h>
class SDLHandler
{
private:
		SDL_Window* window;
		SDL_GLContext glContext;
		GLuint width;  
		GLuint height;

	public:
	SDLHandler(GLuint width, GLuint height);
	~SDLHandler();

	//swap buffers
	void swap();


	//getters
	SDL_Window* getWindow();
	SDL_GLContext getGLContext();
	GLuint getWidth();
	GLuint getHeight();

};

