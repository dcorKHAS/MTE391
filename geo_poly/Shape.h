
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

// Shape - Base Class
class Shape {
public:
    // Virtual draw method
    virtual void draw() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

#endif // SHAPE_H