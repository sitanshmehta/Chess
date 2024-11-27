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

    //Right
    for (int i = x + 1; i < BOARD_SIZE; ++i) {
        //qDebug() << "i in valid: " << i;
        Square* square = board.getSquare(y, i);
        if (!square) {
            break;
        }

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

    /*
    //Left
    for(int i = x - 1; i >= 0; i--){
        qDebug() << "Here";
        if(i < 0) {
            qDebug() << "less than -1";
            break;
        }

        Square* square = board.getSquare(y, i);
        if (!square) {
            break;
        }

        qDebug() << "i:" << i;

        if (square->getPiece() == nullptr) {
            validMoves.push_back(square);
        } else {
            if (square->getPiece()->getColor() != currPieceColor) {
                validMoves.push_back(square);
            }
            break; // Stop searching in this direction after encountering a piece
        }
    }
    */
    //down
    /*for(int i = y + 1; i < BOARD_SIZE; ++i){
        Square* square = board.getSquare(i, x);
        if (!square) {
            break;
        }

        if (square->getPiece() == nullptr) {
            //qDebug() << "Empty square at (" << square->getX() << ", " << square->getY() << ")";
            validMoves.push_back(square);
        } else {
            if (square->getPiece()->getColor() != currPieceColor) {
                validMoves.push_back(square);
            }
            break; // Stop searching in this direction after encountering a piece
        }
    } */

    return validMoves;
}
