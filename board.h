#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include "square.h"
#include <QGridLayout>
#include <QQueue>

static const int BOARD_SIZE = 8;

class Board : public QWidget
{
    Q_OBJECT
public:
    Board(QWidget *parent = nullptr);
    ~Board();

    Square* getSquare(int row, int col) const;
    bool isSquareOnBoard(Square* square) const;
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Square* squares[BOARD_SIZE][BOARD_SIZE];
    QQueue <Piece*> selectedPieces;

    void setupBoard();
    void handleSelectedSquare(int x, int y);
};

#endif // BOARD_H
