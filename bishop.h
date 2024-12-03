#ifndef BISHOP_H
#define BISHOP_H

#include <QPixmap>
#include "piece.h"
#include <vector>

class Square;

class Bishop : public Piece
{
public:
    Bishop(Color color);

    QPixmap getPixmap() const override;
    std::vector<Square*> getValidMoves(const Board& board) const override;

private:
    QPixmap icon;
};

#endif // BISHOP_H
