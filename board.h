//
// Created by Sitansh Mehta on 2022-05-13.
//

#ifndef CHESSBOARD_BOARD_H
#define CHESSBOARD_BOARD_H
#include <iostream>
#include "piece.h"
#include "square.h"

const int SIZE = 8;

class Board{
public:
    Board();
    Board(Square board_m[SIZE][SIZE]);
    void get_board()const;
    void set_board(Square board_m[SIZE][SIZE]);
    void printBoard();
    void isLocationValid(std::string location);
    void findAvailableSquares();


private:
    Square board[SIZE][SIZE];
};

#endif //CHESSBOARD_BOARD_H
