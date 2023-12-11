#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include "Transform.h"


class SDLManager
{
	public:
		SDLManager();//initial Setup
		~SDLManager();//final wrap up
		void handleEvents(bool* running,Transform * transform);// keyboard input etc
		SDL_Window* getWindow();
		void swap();
	private:
		SDL_Window* window;
		SDL_GLContext context;

};


