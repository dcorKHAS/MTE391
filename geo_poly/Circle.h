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

};

#endif // CIRCLE_H
