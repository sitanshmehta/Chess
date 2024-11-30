#include "piece.h"
#include "square.h"
#include "board.h"

Piece::Piece(Color color)
    : color(color),
      currSquare(nullptr)
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

bool Piece::moveToSquare(Square *square)
{
    if(square){
        Square* currSquare = this->getCurrSquare();
        square->setPiece(*this);
        currSquare->setPiece(nullptr);
        this->setCurrSquare(square);
        return true;
    }
    return false;
}
