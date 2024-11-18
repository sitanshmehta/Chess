#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include "square.h"
#include <QGridLayout>


class Board : public QWidget
{
    Q_OBJECT
public:
    Board(QWidget *parent = nullptr);
    ~Board();

    Square* getSquare(int row, int col);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    static const int SQUARES = 8;
    Square* squares[SQUARES][SQUARES];

    void setupBoard();
};

#endif // BOARD_H
