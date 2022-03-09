cmake_minimum_required(VERSION 3.21)
project(tictactoe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tictactoe
        tictactoe.cpp
        )
