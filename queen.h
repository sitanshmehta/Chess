#ifndef QUEEN_H
#define QUEEN_H

#include <QPixmap>
#include "piece.h"
#include <vector>

class Square;

class Queen : public Piece
{
public:
    Queen(Color color);

    QPixmap getPixmap() const override;
    std::vector<Square*> getValidMoves(const Board& board) const override;

private:
    QPixmap icon;
};

#endif // QUEEN_H
