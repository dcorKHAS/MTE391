#ifndef CAT_H
#define CAT_H

#include "Character.h"
#include <cstdlib>

class Cat : public Character {
public:
    Cat(int initX, int initY) : Character(initX, initY) {}

    void render(SDL_Renderer* renderer) override {
        // Draw a filled red triangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color

        // Triangle vertices
        int peakX = x;
        int peakY = y;
        int baseLeftX = x - 20;
        int baseRightX = x + 20;
        int baseY = y + 40;

        // Fill the triangle by drawing horizontal lines from the peak to the base
        for (int row = peakY; row <= baseY; row++) {
            float proportion = (float)(row - peakY) / (baseY - peakY);
            int startX = static_cast<int>(peakX - proportion * 20);
            int endX = static_cast<int>(peakX + proportion * 20);

            for (int col = startX; col <= endX; col++) {
                SDL_RenderDrawPoint(renderer, col, row);
            }
        }
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

#endif // CAT_H
