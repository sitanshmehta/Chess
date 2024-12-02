#ifndef PAWN_H
#define PAWN_H

#include <QPixmap>
#include "piece.h"
#include <vector>

class Square;

class Pawn : public Piece
{
public:
    Pawn(Color color);

    QPixmap getPixmap() const override;
    std::vector<Square*> getValidMoves(const Board& board) const override;

private:
    QPixmap icon;
};

#endif // PAWN_H
