#ifndef TRIANGLE_H
#define TRIANGLE_H

//#include "Shape.h"

// Triangle - Subclass of Shape
class Triangle : public Shape {
public:
    void draw() const {
        std::cout << "   *   " << std::endl;
        std::cout << "  * *  " << std::endl;
        std::cout << " *   * " << std::endl;
        std::cout << "*******" << std::endl;
    }
};

#endif // TRIANGLE_H

