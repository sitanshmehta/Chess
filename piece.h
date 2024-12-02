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
    Square* getCurrSquare() const;
    void setCurrSquare(Square* square);
    void setHasBeenMoved(bool moved);
    bool getHasBeenMoved() const;
    bool moveToSquare(Square *square);

    virtual QPixmap getPixmap() const = 0;
    //Passing 'Board' to 'getValidMoves' is necessary for the piece to calculate valid moves
    //based on the current board state, including obstacles and other pieces.
    virtual std::vector<Square*> getValidMoves(const Board& board) const = 0;

protected:
    Square* currSquare;
    Color color;
    bool hasBeenMoved = false;
};

#endif // PIECE_H
