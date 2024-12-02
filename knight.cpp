#include "knight.h"
#include "piece.h"
#include "board.h"
#include "square.h"
#include "iostream"
#include "utility"
#include <QDebug>

Knight::Knight(Color color)
    : Piece(color)
{
    if (color == WHITE) {
        icon = QPixmap(":/images/images/knight_white.png");
    } else {
        icon = QPixmap(":/images/images/knight_black.png");
    }
}

QPixmap Knight::getPixmap() const
{
    return icon;
}

std::vector<Square*> Knight::getValidMoves(const Board& board) const
{
    std::vector<Square*> validMoves;
    Square* currSquare = this->getCurrSquare();
    if (!currSquare) {
        return validMoves;
    }
    int x = currSquare->getX();
    int y = currSquare->getY();
    Piece::Color currPieceColor = this->getColor();
    const std::vector<std::pair<int, int>> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (const auto& [dx, dy] : offsets) {
        int newX = x + dx;
        int newY = y + dy;
        if (newX >= 0 && newX < BOARD_SIZE && newY >= 0 && newY < BOARD_SIZE) {
            Square* square = board.getSquare(newY, newX);
            if (square) {
                Piece* piece = square->getPiece();
                if (!piece || piece->getColor() != currPieceColor) {
                    validMoves.push_back(square);
                }
            }
        }
    }
    return validMoves;
}
