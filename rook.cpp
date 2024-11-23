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
    int x = currSquare->getX();
    int y = currSquare->getY();

    for(int i = x; i < 8; i++) {
        Square* square = board.getSquare(x, i);
        if(square->getPiece() != nullptr) {
            break;
        }
        validMoves.push_back(square);
    }
    return validMoves;
}
