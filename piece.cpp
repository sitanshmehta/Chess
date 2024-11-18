#include "piece.h"
#include "square.h"
#include "board.h"

Piece::Piece(Color color)
    : color(color), currSquare(nullptr)
{}

Piece::~Piece() {}

Piece::Color Piece::getColor() const
{
    return color;
}

void Piece::setCurrSquare(Square* square)
{
    currSquare = square;
}

Square* Piece::getCurrSquare() const
{
    return currSquare;
}
