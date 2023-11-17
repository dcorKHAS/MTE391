#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>

int main() {
    const int numShapes = 3;
    Shape* shapes[numShapes];

    // Adding different shapes
    shapes[0] = new Circle();
    shapes[1] = new Rectangle();
    shapes[2] = new Triangle();

    // Polymorphic draw calls
    for (int i = 0; i < numShapes; ++i) {
        shapes[i]->draw();
    }

    // Clean up
    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }

    return 0;
}
