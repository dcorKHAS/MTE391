#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include <iostream>
#include <typeinfo>

int main() {
    // Define target location
    int targetX = 3;
    int targetY = 3;

    // Chessboard array
    char board[8][8];
    // Initialize board with dots
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = '.';
        }
    }

    // Array of ChessPiece pointers
    const int numPieces = 3;
    ChessPiece* chessPieces[numPieces] = {
        new Pawn(1, 1),   // Starting position (1, 2)
        new Rook(3, 0),   // Starting position (0, 0)
        new Knight(1, 2)  // Starting position (1, 0)
    };

    // Check which pieces can move to the target location
    for (int i = 0; i < numPieces; ++i) {
        if (chessPieces[i]->isMoveLegal(targetX, targetY)) {
            std::cout << "The piece at location (" << chessPieces[i]->getStartX() << ", "
                << chessPieces[i]->getStartY() << ") can move to the target location ("
                << targetX << ", " << targetY << ")." << std::endl;
        }

        char pieceChar = '.';

        Pawn* myPointer = dynamic_cast<Pawn*>(chessPieces[i]);
        Pawn* myNullpointer=NULL;

        if (dynamic_cast<Pawn*>(chessPieces[i])) pieceChar = 'P';
        else if (dynamic_cast<Rook*>(chessPieces[i])) pieceChar = 'R';
        else if (dynamic_cast<Knight*>(chessPieces[i])) pieceChar = 'K';

        board[chessPieces[i]->getStartX()][chessPieces[i]->getStartY()] = pieceChar;
    }

    // Mark the target location with 'X'
    board[targetX][targetY] = 'X';

    // Print the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Clean up manually
    for (int i = 0; i < numPieces; ++i) {
        delete chessPieces[i];
    }

    return 0;
}
