#include "board.h"
#include "square.h"
#include <QGridLayout>


Board::Board(QWidget *parent)
    : QWidget(parent)
{
    setupBoard();
}

Board::~Board()
{
    for(int row = 0; row < SQUARES; ++row) {
        for(int col = 0; col < SQUARES; ++col) {
            delete squares[row][col];
        }
    }
}

void Board::setupBoard()
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(0);
    //grid->setMargin(0);

    for (int row = 0; row < SQUARES; ++row) {
        for(int col = 0; col < SQUARES; ++col) {
            squares[row][col] = new Square(col, row, this);
            grid->addWidget(squares[row][col], row, col);
        }
    }

    setLayout(grid);
}

void Board::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}
