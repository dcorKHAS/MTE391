#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>


class SDLManager
{
	public:
		SDLManager();//initial Setup
		~SDLManager();//final wrap up
		void handleEvents(bool* running, glm::vec3* offset, float speed);// keyboard input etc
		SDL_Window* getWindow();
		void swap();
	private:
		SDL_Window* window;
		SDL_GLContext context;

};


