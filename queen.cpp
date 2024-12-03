#include "queen.h"
#include "piece.h"
#include "board.h"
#include "square.h"
#include "iostream"
#include "utility"
#include <QDebug>

Queen::Queen(Color color)
    : Piece(color)
{
    if (color == WHITE) {
        icon = QPixmap(":/images/images/queen_white.png");
    } else {
        icon = QPixmap(":/images/images/queen_black.png");
    }
}

QPixmap Queen::getPixmap() const
{
    return icon;
}

std::vector<Square*> Queen::getValidMoves(const Board& board) const
{
    std::vector<Square*> validMoves;

    return validMoves;
}
