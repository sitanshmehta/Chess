#ifndef KNIGHT_H
#define KNIGHT_H

#include <QPixmap>
#include "piece.h"
#include <vector>

class Square;

class Knight : public Piece
{
public:
    Knight(Color color);

    QPixmap getPixmap() const override;
    std::vector<Square*> getValidMoves(const Board& board) const override;

private:
    QPixmap icon;
};

#endif // KNIGHT_H
