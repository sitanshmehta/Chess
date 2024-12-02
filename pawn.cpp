#include "pawn.h"
#include "piece.h"
#include "board.h"
#include "square.h"
#include "utility"

Pawn::Pawn(Color color)
    : Piece(color)
{
    if (color == WHITE) {
        icon = QPixmap(":/images/images/pawn_white.png");
    } else {
        icon = QPixmap(":/images/images/pawn_black.png");
    }
}

QPixmap Pawn::getPixmap() const
{
    return icon;
}

std::vector<Square*> Pawn::getValidMoves(const Board& board) const
{
    std::vector<Square*> validMoves;
    Square* currSquare = this->getCurrSquare();
    if (!currSquare) {
        return validMoves;
    }
    int x = currSquare->getX();
    int y = currSquare->getY();
    Piece::Color currPieceColor = this->getColor();
    int direction = (currPieceColor == Piece::Color::WHITE) ? -1 : 1;
    int newY = y + direction;
    if (newY >= 0 && newY < BOARD_SIZE) {
        Square* forwardSquare = board.getSquare(newY, x);
        if (forwardSquare && forwardSquare->getPiece() == nullptr) {
            validMoves.push_back(forwardSquare);
            if (!hasBeenMoved) {
                int newY2 = newY + direction;
                if (newY2 >= 0 && newY2 < BOARD_SIZE) {
                    Square* forwardSquare2 = board.getSquare(newY2, x);
                    if (forwardSquare2 && forwardSquare2->getPiece() == nullptr) {
                        validMoves.push_back(forwardSquare2);
                    }
                }
            }
        }
        int captureXLeft = x - 1;
        int captureXRight = x + 1;
        if (captureXLeft >= 0) {
            Square* leftCapture = board.getSquare(newY, captureXLeft);
            if (leftCapture && leftCapture->getPiece() && leftCapture->getPiece()->getColor() != currPieceColor) {
                validMoves.push_back(leftCapture);
            }
        }
        if (captureXRight < BOARD_SIZE) {
            Square* rightCapture = board.getSquare(newY, captureXRight);
            if (rightCapture && rightCapture->getPiece() && rightCapture->getPiece()->getColor() != currPieceColor) {
                validMoves.push_back(rightCapture);
            }
        }
    }
    return validMoves;
}

