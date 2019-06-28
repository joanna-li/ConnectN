//
// Created by Joanna on 2019-05-01.
//

#include <string>
#include "Move.h"

ConnectNGame::Move::Move(const ConnectNGame::Player& maker) : maker(maker), row(-99), col(-98), parsedSuccessfully(false) {

}

void ConnectNGame::Move::parseInput(std::stringstream& input) {
    parsedSuccessfully = static_cast<bool>(input); //input must start out as being good

    input >> col;
    //we must have read col
    // parsedSuccessfully = parsedSuccessfully && static_cast<bool>(input);
    std::string leftovers;
    input >> leftovers;
    //and we weren't able to read anything after the row and col
    parsedSuccessfully = parsedSuccessfully && !input;

}

bool ConnectNGame::Move::isValid(const Board& board) const{

    return parsedSuccessfully && board.inBounds(col) && board.checkAvailableRow(col);
}

void ConnectNGame::Move::make(ConnectNGame::Board& board) {
    board.set(col, maker.getPiece());
}

// find first available position in row
