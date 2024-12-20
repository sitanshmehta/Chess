#ifndef ROOK_H
#define ROOK_H

#include <QPixmap>
#include "piece.h"
#include <vector>

class Square;

class Rook : public Piece
{
public:
    Rook(Color color);

    QPixmap getPixmap() const override;
    std::vector<Square*> getValidMoves(const Board& board) const override;

private:
    QPixmap icon;
};

#endif // ROOK_H
