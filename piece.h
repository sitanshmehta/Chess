//
// Created by Sitansh Mehta on 2022-05-13.
//

#ifndef CHESSBOARD_PIECE_H
#define CHESSBOARD_PIECE_H
#include "board.h"
#include "square.h"
#include <iostream>

class PieceType{
public:
    PieceType();
    PieceType(std::string name_m, std::string availableMoves_m, Square location_m, bool white_m);
    void get_name()const;
    void get_availableMoves()const;
    void get_location()const;
    void get_white()const;
    void set_name(std::string name_m);
    void set_availableMoves(std::string availableMoves_m);
    void set_location(Square location_m);
    void set_white(bool white_m);
    void findAvailableMoves();
    bool movePiece(Square location);


private:
    std::string name;
    std::string availableMoves; //one piece can have multiple available moves, should this be an array? What size?
    Square location;
    bool white;
};

#endif //CHESSBOARD_PIECE_H
