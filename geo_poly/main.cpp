#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <random>
#include <time.h>

int main() {
    const int numShapes = 3; //const allows use of numShapes as arraySize
    Shape* shapes[numShapes];

    // Adding different shapes
    shapes[0] = new Circle(); //new keyword creates an object and returns its pointer
    shapes[1] = new Rectangle();
    
    srand(time(NULL));

    std::cout << (double)rand() / (double)RAND_MAX << std::endl;
    
    shapes[2] = new Rectangle();

      
    

    // Polymorphic draw calls
    for (int i = 0; i < numShapes; ++i) {
        shapes[i]->draw(); //  object.method()  ptrToObject->method() 
    }

    // Clean up
    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }

    return 0;
}
