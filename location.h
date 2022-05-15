//
// Created by Sitansh Mehta on 2022-05-14.
//


#ifndef CHESSBOARD_LOCATION_H
#define CHESSBOARD_LOCATION_H
#include <iostream>

class Location{
public:
    Location();
    Location(std::string row_m, std::string col_m);
    void get_row()const;
    void get_col()const;
    void set_row(std::string row_m);
    void set_col(std::string col_m);


private:
    std::string row;
    std::string col;
};
#endif //CHESSBOARD_LOCATION_H
