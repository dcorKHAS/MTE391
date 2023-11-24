#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>

class Character {
protected:
    int x, y;

public:
    Character(int initX, int initY) : x(initX), y(initY) {}

    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void move() = 0;

    virtual ~Character() {}
};

#endif // CHARACTER_H
