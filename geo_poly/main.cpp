#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <random>
#include <time.h>
/*
int main() {
    const int numShapes = 3; //const allows use of numShapes as arraySize
    Shape* shapes[numShapes];

    // Adding different shapes
    shapes[0] = new Circle(); //new keyword creates an object and returns its pointer
    shapes[1] = new Rectangle();
    
    //srand(time(NULL));

    //std::cout << static_cast<double>(rand()) / static_cast<double>(RAND_MAX) << std::endl;
    
    shapes[2] = new Triangle();

      
    

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
*/

int main(int argc, char* argv[]) {
    
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Geoshape", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,0 );
    const int numShapes = 3; //const allows use of numShapes as arraySize
    Shape* shapes[numShapes];

    // Adding different shapes
    shapes[0] = new Circle(50,50); //new keyword creates an object and returns its pointer
    shapes[1] = new Rectangle(45, 56);

    //srand(time(NULL));

    //std::cout << static_cast<double>(rand()) / static_cast<double>(RAND_MAX) << std::endl;

    shapes[2] = new Triangle(60,20);

 

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

       

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // Clear with white background
          SDL_RenderClear(renderer);
        for (int i = 0; i < numShapes; i++) {

            shapes[i]->render(renderer);
    }
      

     ///render calls

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
