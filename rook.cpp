#include "rook.h"
#include "piece.h"
#include"board.h"
#include "square.h"
#include "iostream"

Rook::Rook(Color color)
    : Piece(color)
{
    if (color == WHITE) {
        icon = QPixmap(":/images/images/rook_white.png");
    } else {
        icon = QPixmap(":/images/images/rook_black.png");
    }
}

QPixmap Rook::getPixmap() const
{
    return icon;
}

/*
std::vector<Square*> Rook::getValidMoves(const Board& board) const
{
    std::vector<Square*> validMoves;

    Square* currSquare = this->getCurrSquare();
    Piece* currPiece = currSquare->getPiece();
    Color currPieceColor = currPiece->getColor();

    int x = currSquare->getX();
    int y = currSquare->getY();

    //qDebug() << "x: " << x << "y" << y;
    //Right
    for(int i = x + 1; i < BOARD_SIZE; ++i) {
        Square* square = board.getSquare(y, i);

        if(square == nullptr){
            break;
        }

        qDebug() << "X: " << square->getX() << "Y: " << square->getY();

        //qDebug() <<square->getX() << " "<< square->getY();
        if(square->getPiece() == nullptr) {
            validMoves.push_back(square);
            //continue;
        } else{
            if (square->getPiece()->getColor() != currPieceColor) {
                validMoves.push_back(square);
            }
            break;
        }
    }
    return validMoves;
}
*/

std::vector<Square*> Rook::getValidMoves(const Board& board) const
{
    std::vector<Square*> validMoves;

    Square* currSquare = this->getCurrSquare();
    if (!currSquare) {
        return validMoves; // Safety check in case currSquare is nullptr
    }

    int x = currSquare->getX();
    int y = currSquare->getY();

    Piece::Color currPieceColor = this->getColor();

    // Right
    for (int i = x + 1; i < BOARD_SIZE; ++i) {
        Square* square = board.getSquare(y, i);
        if (!square) {
            break;
        }

        //qDebug() << "X: " << square->getX() << "Y: " << square->getY();

        if (square->getPiece() == nullptr) {
            //qDebug() << "Empty square at (" << square->getX() << ", " << square->getY() << ")";
            validMoves.push_back(square);
        } else {
            if (square->getPiece()->getColor() != currPieceColor) {
                validMoves.push_back(square);
            }
            break; // Stop searching in this direction after encountering a piece
        }
    }
    return validMoves;
}
