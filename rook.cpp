#include "rook.h"
#include "piece.h"
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

std::vector<Square*> Rook::getValidMoves(const Board &board) const
{
    std::vector<Square*> validMoves;

    //Square* currSquare = this->getCurrSquare();
    return validMoves;
}
