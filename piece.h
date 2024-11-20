#ifndef PIECE_H
#define PIECE_H

#include <QWidget>
#include <QPixmap>
#include <vector>

class Square;
class Board;


class Piece
{
public:
    enum Color {
        BLACK = 0,
        WHITE = 1
    };

    Piece(Color color);
    virtual ~Piece();

    Color getColor() const;
    void setCurrSquare(Square* square);
    Square* getCurrSquare() const;

    //virtual QPixmap getPixmap() const = 0;
    //virtual std::vector<Square*> getValidMoves(const Board& board) const = 0;
    //virtual bool moveToSquare(Piece *piece, Square *square) = 0;

protected:
    Square* currSquare;
    Color color;
};

#endif // PIECE_H
