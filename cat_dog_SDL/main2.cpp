#include <SDL.h>
#include "Dog.h"
#include "Cat.h"
#include <iostream>

int main2(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Animal Movement", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Dog dog(100, 100);
    Cat cat(200, 200);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        int cat_dx = 0, cat_dy = 0;
        int dog_dx = 0, dog_dy = 0;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_w: cat_dy = -1; break;
                case SDLK_s: cat_dy = 1; break;
                case SDLK_a: cat_dx = -1; break;
                case SDLK_d: cat_dx = 1; break;
                case SDLK_UP: dog_dy = -1; break;
                case SDLK_DOWN: dog_dy = 1; break;
                case SDLK_LEFT: dog_dx = -1; break;
                case SDLK_RIGHT: dog_dx = 1; break;
                }
            }
        }

      /*  cat.move(cat_dx, cat_dy);
        dog.move(dog_dx, dog_dy);*/

        cat.move();
        dog.move();

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // Clear with white background
        SDL_RenderClear(renderer);

        dog.render(renderer);
        cat.render(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
