cmake_minimum_required(VERSION 3.21)
project(chessBoard)

set(CMAKE_CXX_STANDARD 14)

add_executable(chessBoard main.cpp piece.h board.h square.h location.h)
