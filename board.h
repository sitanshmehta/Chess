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
    void setSelectedPiece(Piece* piece);
    bool isSquareOnBoard(Square* square) const;
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Square* squares[BOARD_SIZE][BOARD_SIZE];
    Piece* selectedPiece = nullptr;

    void setupBoard();
    void handleSquarePressAndHold(int x, int y);
    void handleSquareClicked(int x, int y);
    bool isSquareInValidMoves(std::vector<Square*> validMoves, Square *square);
};

#endif // BOARD_H
