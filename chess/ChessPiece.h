#ifndef CHESSPIECE_H
#define CHESSPIECE_H

class ChessPiece {
protected:
    int startX;
    int startY;

public:
    ChessPiece(int x, int y) : startX(x), startY(y) {    }

    virtual bool isMoveLegal(int endX, int endY) const = 0;

    int getStartX() const { return startX; }
    int getStartY() const { return startY; }

    virtual ~ChessPiece() {}
};

#endif // CHESSPIECE_H
