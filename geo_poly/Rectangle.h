#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

// Rectangle - Subclass of Shape
class Rectangle : public Shape {
public:
    void draw()  const override {
        std::cout << "*******" << std::endl;
        std::cout << "*     *" << std::endl;
        std::cout << "*     *" << std::endl;
        std::cout << "*******" << std::endl;
    }
    void render(SDL_Renderer* renderer) const override {
        // Draw a blue rectangle
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
        SDL_Rect rect = { x, y, 40, 30 }; // Rectangle dimensions
        SDL_RenderFillRect(renderer, &rect);
    }

    Rectangle(int x, int y) :Shape(x, y) {}
};

#endif // RECTANGLE_H

