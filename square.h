#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QWidget>
#include "piece.h"

class Piece;

//Each square will handle mouse events and display graphical content, therefore it inherits QWidget
class Square : public QWidget
{
    //For signals and slots in the square class
    Q_OBJECT

public:
    Square(int x, int y, QWidget *parent = nullptr);

    int getX() const;
    int getY() const;
    Piece* getPiece() const;
    bool getHighlighted() const;

    void setPiece(Piece* newPiece);
    void setHighlighted(bool highlight);
    //pbr to avoid copying, declared as static since it isnt instance specific
    static void highlightSetOfSquares(const std::vector<Square*> &squares, bool highlight);

signals:
    void squareClicked(int x, int y);

//override default behavior of paintEvent function that paints widgets
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    int x;
    int y;
    Piece *piece;
    bool isHighLighted = false;
};

#endif // SQUARE_H
