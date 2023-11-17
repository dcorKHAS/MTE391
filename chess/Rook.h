#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
public:
    Rook(int x, int y) : ChessPiece(x, y) {}

    bool isMoveLegal(int endX, int endY) const override {
        return startX == endX || startY == endY;
    }
};

#endif // ROOK_H

