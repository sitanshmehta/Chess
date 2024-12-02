#include "rook.h"
#include "piece.h"
#include "board.h"
#include "square.h"
#include "iostream"
#include "utility"

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
        return validMoves; // Safety check
    }

    int x = currSquare->getX();
    int y = currSquare->getY();
    Piece::Color currPieceColor = this->getColor();

    const std::vector<std::pair<int, int>> directions = {
        {1, 0},  // Right
        {-1, 0}, // Left
        {0, 1},  // Down
        {0, -1}  // Up
    };

    for (const auto& [dx, dy] : directions) {
        int newX = x + dx;
        int newY = y + dy;

        while (newX >= 0 && newX < BOARD_SIZE &&
               newY >= 0 && newY < BOARD_SIZE) {

            Square* square = board.getSquare(newY, newX);
            if (!square) {
                break; // Invalid square
            }

            if (square->getPiece() == nullptr) {
                validMoves.push_back(square);
            } else {
                if (square->getPiece()->getColor() != currPieceColor) {
                    validMoves.push_back(square);
                }
                break; // Blocked by a piece
            }

            newX += dx;
            newY += dy;
        }
    }

    return validMoves;
}
