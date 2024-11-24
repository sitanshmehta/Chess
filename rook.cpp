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
    Piece* currPiece = currSquare->getPiece();
    Color currPieceColor = currPiece->getColor();

    int x = currSquare->getX();
    int y = currSquare->getY();

    qDebug() << "x: " << x << "y" << y;
    //Up
    for(int i = x; i < 8; i--) {
        Square* square = board.getSquare(x + 1, i);

        qDebug() << "X: " << square->getX() << "Y" << square->getY();

        qDebug() << i << " " << x;
        //qDebug() <<square->getX() << " "<< square->getY();
        if(square->getPiece() == nullptr) {
            //qDebug() << "here";
            validMoves.push_back(square);
            continue;
        } else {
            break;
        }
        //if(currPiece != nullptr && square->getPiece()->getColor() != currPieceColor){
            //validMoves.push_back(square);
        //}
        validMoves.push_back(square);
    }
    return validMoves;
}
