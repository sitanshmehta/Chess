#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QWidget>
#include "piece.h"


//Each square will handle mouse events and display graphical content, therefore it inherits QWidget
class Square : public QWidget
{
    friend class Piece; //this allows a piece to access x and y so that we know where the piece is
    //For signals and slots in the square class
    Q_OBJECT

public:
    Square(int x, int y, QWidget *parent = nullptr);

    int getX() const;
    int getY() const;
    Piece* getPiece() const;
    void setPiece(Piece* newPiece);

//override default behavior of paintEvent function that paints widgets
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int x;
    int y;
    Piece *piece;
};

#endif // SQUARE_H
