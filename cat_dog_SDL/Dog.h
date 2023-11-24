#ifndef DOG_H
#define DOG_H

#include "Character.h"
#include <cstdlib>

class Dog : public Character {
public:
    Dog(int initX, int initY) : Character(initX, initY) {}

    void render(SDL_Renderer* renderer) override {
        // Draw a blue rectangle
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
        SDL_Rect rect = { x, y, 40, 30 }; // Rectangle dimensions
        SDL_RenderFillRect(renderer, &rect);
    }

    void move() override {
        x += rand() % 3 - 1; // Random move
        y += rand() % 3 - 1;
    }



    //void move(int dx, int dy) override {
    //    x += dx;
    //    y += dy;
    //}


};

#endif // DOG_H
