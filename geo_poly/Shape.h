
#ifndef SHAPE_H //include guard
#define SHAPE_H

#include <iostream>
#include <SDL.h> //
// Shape - Base Class
class Shape {
protected:

    int  x;
    int  y;

public:
    // Virtual draw method
    virtual void draw() const = 0; //const means that the method does not change the state of the object
    virtual void render(SDL_Renderer* renderer) const = 0;
    // Virtual destructor
   
    Shape(int x, int y) :y(y), x(x) {}
    virtual ~Shape() {}
};

#endif // SHAPE_H
