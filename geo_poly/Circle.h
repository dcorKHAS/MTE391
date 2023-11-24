#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

// Circle - Subclass of Shape
class Circle : public Shape {
public:

    void draw() const override {
        std::cout << "  ***  " << std::endl;
        std::cout << " *   * " << std::endl;
        std::cout << "*     *" << std::endl;
        std::cout << " *   * " << std::endl;
        std::cout << "  ***  " << std::endl;
    }
    void render(SDL_Renderer* renderer) const override
    {
        const int radius = 50;
        const int32_t diameter = (radius * 2);

        int32_t xx = (radius - 1);
        int32_t yy = 0;
        int32_t tx = 1;
        int32_t ty = 1;
        int32_t error = (tx - diameter);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        while (xx >= yy)
        {
            // Each of the following renders an octant of the circle
            SDL_RenderDrawPoint(renderer, x + xx, y - yy);
            SDL_RenderDrawPoint(renderer, x + xx, y + yy);
            SDL_RenderDrawPoint(renderer, x - xx, y - yy);
            SDL_RenderDrawPoint(renderer, x - xx, y + yy);
            SDL_RenderDrawPoint(renderer, x + yy, y - xx);
            SDL_RenderDrawPoint(renderer, x + yy, y + xx);
            SDL_RenderDrawPoint(renderer, x - yy, y - xx);
            SDL_RenderDrawPoint(renderer, x - yy, y + xx);

            if (error <= 0)
            {
                ++yy;
                error += ty;
                ty += 2;
            }

            if (error > 0)
            {
                --xx;
                tx += 2;
                error += (tx - diameter);
            }
        }

    }
    Circle(int x, int y) :Shape(x, y) {}

};



#endif // CIRCLE_H
