cmake_minimum_required(VERSION 3.14)
project(ConnectNGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConnectNGame main.cpp Player.cpp Player.h Board.cpp Board.h Move.cpp Move.h ConnectN.cpp ConnectN.h)