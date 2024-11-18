#ifndef PIECE_H
#define PIECE_H

#include <QWidget>

class Piece : public QWidget
{
    Q_OBJECT
public:
    Piece(QWidget *parent = nullptr);
    ~Piece();

    //use pure virtual functions for methods implemented by inherited classes
    void setPiecePixmap();
    void getPiecePixmap();
    void whereIsPiece(Piece* piece);

    enum TYPE {
        BLACK = 0,
        WHITE = 1
    };

private:
    QPixmap icon;
};

#endif // PIECE_H
