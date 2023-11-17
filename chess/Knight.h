#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
#include <stdlib.h>

class Knight : public ChessPiece {
public:
    Knight(int x, int y) : ChessPiece(x, y) {}

    bool isMoveLegal(int endX, int endY) const override {
        return (abs(startX - endX) == 2 && abs(startY - endY) == 1) ||
            (abs(startX - endX) == 1 && abs(startY - endY) == 2);
    }
};

#endif // KNIGHT_H

