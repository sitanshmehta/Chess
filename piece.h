#ifndef PIECE_H
#define PIECE_H

#include <QWidget>
#include <QPixmap>
#include <vector>

class Board;
class Square;


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

    virtual QPixmap getPixmap() const = 0;
    //Passing 'Board' to 'getValidMoves' is necessary for the piece to calculate valid moves
    //based on the current board state, including obstacles and other pieces.
    virtual std::vector<Square*> getValidMoves(const Board& board) const = 0;
    //virtual bool moveToSquare(Piece *piece, Square *square) = 0;

protected:
    Square* currSquare;
    Color color;
    bool selected;
};

#endif // PIECE_H
