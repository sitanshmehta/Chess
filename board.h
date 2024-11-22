#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include "square.h"
#include <QGridLayout>

static const int BOARD_SIZE = 8;

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
    Square* squares[BOARD_SIZE][BOARD_SIZE];

    void setupBoard();
};

#endif // BOARD_H
