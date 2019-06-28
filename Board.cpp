//
// Created by Joanna on 2019-05-01.
//
#include <iostream>
#include "Board.h"

ConnectNGame::Board::Board(int row, int col, char blankSpace) :
        boardState(row, std::string(col, blankSpace)),
        blankSpace(blankSpace) {

}

int ConnectNGame::Board::getRowSize() const {
    // find length of vector
    return boardState.size();
}

int ConnectNGame::Board::getColSize() const {
    // find length of string inside vector
    return boardState.at(0).length();
}

int ConnectNGame::Board::getFirstAvailableRowNo(int col) const {
    for (int row = getRowSize() - 1; row >=0; --row) {
        if(isBlankSpace(row, col)){
            return row;
        }
    }
    return -99;
}

void ConnectNGame::Board::display(int rowNum) const {

    //print column headers
    std::cout << "  ";
    for (int i = 0; i < getColSize(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = rowNum - 1;
    for (const auto& row : boardState) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex--;
        std::cout << std::endl;
        if (rowIndex < 0){
            break;
        }
    }
}
// checking for valid column number from user input
bool ConnectNGame::Board::inBounds(int col) const {
    return isBetween(col, 0, getColSize() - 1);
}

bool ConnectNGame::Board::isBetween(int val, int lower, int upper) {
    return val >= lower && val <= upper;
}

bool ConnectNGame::Board::isBlankSpace(int row, int col) const {
    return boardState.at(row).at(col) == blankSpace;
}

bool ConnectNGame::Board::isBlankSpace2(int col) const { // check if blankChar available
    for (int row = 0; row < getRowSize(); ++row) {
        if(isBlankSpace(row, col)){
            return true;
        }
    }
    return false;
}

void ConnectNGame::Board::set(int col, char val) {
    int row = rowPosition(col);
    boardState.at(row).at(col) = val;
}

// reverse looping because row is 0 at the bottom
int ConnectNGame::Board::rowPosition(int col) const {
    for (int row = getRowSize()-1; row >= 0; --row) {
        if (isBlankSpace(row, col)) {
            return row;
        }
    }
    return -99;
}

ConnectNGame::Board::iterator ConnectNGame::Board::begin() {
    return boardState.begin();
}

ConnectNGame::Board::iterator ConnectNGame::Board::end() {
    return boardState.end();
}

ConnectNGame::Board::const_iterator ConnectNGame::Board::cbegin() const {
    return boardState.cbegin();
}

ConnectNGame::Board::const_iterator ConnectNGame::Board::cend() const {
    return  boardState.cend();
}

const char ConnectNGame::Board::getblankSpace() const {
    return blankSpace;
}

// check to see if space in row is available or not for piece
bool ConnectNGame::Board::checkAvailableRow(int col) const {
    for (int row = 0; row <= getRowSize(); ++row){
        if (isBlankSpace(row, col)) {
            return true;
        }
    }
    return false;
}

const char& ConnectNGame::Board::at(int row, int col) const {
    return boardState.at(row).at(col);
}
// all spaces filled with player pieces
bool ConnectNGame::Board::full() const {
    for (int row = 0; row < getRowSize(); ++row) {
        for (int col = 0; col < getColSize(); ++col) {
            if(!isBlankSpace(row, col)){
                return false;
            }
        }
    }
    return true;
}

