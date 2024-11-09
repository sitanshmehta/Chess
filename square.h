//
// Created by Sitansh Mehta on 2022-05-13.
//

#ifndef CHESSBOARD_SQUARE_H
#define CHESSBOARD_SQUARE_H
#include <iostream>
#include "location.h"

class Square
{
public:
    Square();
    Square(std::string color_m, std::string location_m);
    void get_color() const;
    void get_location() const;
    void set_color(std::string color_m);
    void set_location(std::string location_m);

private:
    std::string color;
    Location squareLocation;
};

#endif // CHESSBOARD_SQUARE_H
