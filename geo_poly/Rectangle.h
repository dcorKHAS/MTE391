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

};

#endif // RECTANGLE_H
