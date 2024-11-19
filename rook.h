#ifndef ROOK_H
#define ROOK_H

#include <QPixmap>
#include

class Rook : public Piece
{
    Q_OBJECT
public:
    Rook(Color color, QPixmap icon, QWidget *parent = nullptr);

    //overriden virtual functions
    QPixmap getPixmap() const override;
    std::vector<Square*> getValidMoves(const Board& board) const override;
    bool moveToSquare(Piece *piece, Square* square) override;


private:
    QPixmap icon;

};

#endif // ROOK_H
