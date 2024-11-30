#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>
#include <QTimer>
#include "piece.h"

class Piece;

//Each square will handle mouse events and display graphical content, therefore it inherits QWidget
class Square : public QWidget
{
    //For signals and slots in the square class
    Q_OBJECT

public:
    Square(int x, int y, QWidget *parent);
    ~Square();

    int getX() const;
    int getY() const;
    Piece* getPiece() const;
    bool getHighlighted() const;

    void setPiece(Piece* newPiece);
    void setHighlighted(bool highlight);
    static void highlightSetOfSquares(const std::vector<Square*> &squares, bool highlight);

signals:
    void squareClicked(int x, int y);
    void squareHeld(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int x;
    int y;
    Piece *piece;
    bool isHighLighted = false;
    QTimer* pressAndHoldTimer;
};

#endif // SQUARE_H
