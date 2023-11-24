#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

// Triangle - Subclass of Shape
class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << "   *   " << std::endl;
        std::cout << "  * *  " << std::endl;
        std::cout << " *   * " << std::endl;
        std::cout << "*******" << std::endl;
    }

    void render(SDL_Renderer* renderer) const override {
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
    Triangle(int x, int y) : Shape(x, y) {}

};

#endif // TRIANGLE_H

