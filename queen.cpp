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
    Square* currSquare = this->getCurrSquare();

    if (!currSquare) {
        return validMoves;
    }

    int x = currSquare->getX();
    int y = currSquare->getY();
    Piece::Color currPieceColor = this->getColor();

    const std::vector<std::pair<int, int>> directions = {
        {1, 0},    // Right
        {-1, 0},   // Left
        {0, 1},    // Down
        {0, -1},   // Up
        {1, 1},    // Down-Right
        {1, -1},   // Up-Right
        {-1, 1},   // Down-Left
        {-1, -1}   // Up-Left
    };

    for (const auto& [dx, dy] : directions) {
        int newX = x + dx;
        int newY = y + dy;

        while (newX >= 0 && newX < BOARD_SIZE && newY >= 0 && newY < BOARD_SIZE) {
            Square* square = board.getSquare(newY, newX);
            if (!square) {
                break;
            }
            Piece* piece = square->getPiece();
            if (!piece) {
                validMoves.push_back(square);
            } else {
                if (piece->getColor() != currPieceColor) {
                    validMoves.push_back(square);
                }
                break;
            }
            newX += dx;
            newY += dy;
        }
    }

    return validMoves;
}

