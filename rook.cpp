#include "rook.h"
#include "piece.h"

Rook::Rook(Color color)
    : Piece(color)
{
    if (color == WHITE) {
        icon = QPixmap(":/images/rook_white.png");
    } else {
        icon = QPixmap(":/images/rook_black.png");
    }
}
