#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
    Pawn(int x, int y) : ChessPiece(x, y) {}

    bool isMoveLegal(int endX, int endY) const override {
        return startX == endX && (endY == startY + 1);
    }
};

#endif // PAWN_H
