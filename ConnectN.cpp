//
// Created by Joanna on 2019-05-01.
//
#include <iostream>
#include <sstream>
#include "Move.h"
#include "ConnectN.h"

ConnectNGame::ConnectN::ConnectN(int row, int col) :
        board(row, col, '*'), players(2), playerTurn(-1) {

}

void ConnectNGame::ConnectN::play(int rowNum, int winNum) {
    determineStartingPlayer();

    while (true) {
        board.display(rowNum); //show the game state
        //get move
        Move move = getValidMove();
        //make move
        move.make(board);
        //makeMove(move);
        if (isGameOver(winNum)) {
            break;
        }
        //switch the turn
        changeTurn();
    }
    //
    board.display(rowNum);
    //declare the results
    declareResults(winNum);

}

void ConnectNGame::ConnectN::determineStartingPlayer() {
    playerTurn = 0;
}

ConnectNGame::Move ConnectNGame::ConnectN::getValidMove() const {
    Move playerMove(getCurrentPlayer());
    do {
        std::cout << "Enter the column you want to play in: ";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream userIn(line);
        playerMove.parseInput(userIn);
    } while (!playerMove.isValid(board));
    return playerMove;
}

const ConnectNGame::Player& ConnectNGame::ConnectN::getCurrentPlayer() const {
    return players.at(playerTurn);
}

ConnectNGame::Player& ConnectNGame::ConnectN::getCurrentPlayer() {
    return players.at(playerTurn);
}

bool ConnectNGame::ConnectN::isGameOver(int winNum) const {
    return gameWon(winNum) || tie(winNum);
}

bool ConnectNGame::ConnectN::gameWon(int winNum) const {
    return horzWin(winNum) || vertWin(winNum) || diagWin(winNum);
}

bool ConnectNGame::ConnectN::horzWin(int winNum) const {
    // start from bottom 0 row to top row
    for (auto rowItr = board.cend()-1; rowItr >= board.cbegin(); --rowItr) {
        auto elemItr = rowItr->cbegin();
        // get current player entered piece
        char firstChar = getCurrentPlayer().getPiece();
        bool allSame = true;
        int count = 0;
        // loop through each char in column
        for (; elemItr != rowItr->cend(); ++elemItr) {
            if (*elemItr != firstChar) {
                allSame = false;
                // loop through until you get to player piece
                count = 0;
                continue;
            }
            ++count;
            if (count >= winNum){
                break;
            }
        }
        if (allSame || count >= winNum) {
            return true;
        }
    }
    return false;
}



bool ConnectNGame::ConnectN::vertWin(int winNum) const {
    int colSize = board.getColSize();
    int rowSize = board.getRowSize();
    for (int col = 0; col != colSize; ++col) {
        if (board.isBlankSpace(rowSize-1, col)) {
            continue;
        }
        bool allSame = true;
        int count = 0;
        char firstChar = getCurrentPlayer().getPiece();
        for (int row = rowSize-1; row >= 0; --row) {
            if (board.at(row, col) != firstChar) {
                allSame = false;
                continue;
            }
            ++count;
            if (count >= winNum){
                break;
            }
        }
        if (allSame || count >= winNum) {
            return true;
        }
    }
    return false;
}

//X
//  X
//    X

bool ConnectNGame::ConnectN::diagWin(int winNum) const {
    return leftDiagWin(winNum) || rightDiagWin(winNum);
}

//X
//  X
//    X
bool ConnectNGame::ConnectN::leftDiagWin(int winNum) const {
    char firstChar = getCurrentPlayer().getPiece();
    int colSize = board.getColSize();
    int rowSize = board.getRowSize();
    int diff = colSize - rowSize;

    if (diff >=0) {
        // loop through the columns
        for (int i = 0; i <= colSize - rowSize; ++i) {
            // shifts search column from left to right one at a time
            for (int v = 0; v <= rowSize - winNum; ++v) {
                bool allSame = true;
                int count = 0;

                for (int r = 0; r < rowSize - v; ++r) {
                    char curChar = board.at(r+v, r+i);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count >= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum){
                    return true;
                }
            }
            for (int h = 0; h <= rowSize - winNum; ++h) {
                bool allSame = true;
                int count = 0;

                for (int r = 0; r < rowSize - h; ++r){
                    char curChar = board.at(r, r+h+i);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count>= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum) {
                    return true;
                }
            }
        }
        return false;
    }
    else {
        for (int i = 0; i <= rowSize - colSize; ++i) {

            // shifts search column from left to right one at a time
            for (int v = 0; v < colSize - winNum; ++v) {
                bool allSame = true;
                int count = 0;

                for (int r = 0; r < colSize - v; ++r) {
                    char curChar = board.at(r+i+v, r);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count >= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum){
                    return true;
                }
            }
            for (int h = 0; h <= colSize - winNum; ++h) {
                bool allSame = true;
                int count = 0;

                for (int r = 0; r < colSize - h; ++r){
                    char curChar = board.at(r + i, r + h);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count>= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum) {
                    return true;
                }
            }
        }
        return false;
    }
}

//    X
//  X
//X
bool ConnectNGame::ConnectN::rightDiagWin(int winNum) const {
    char firstChar = getCurrentPlayer().getPiece();
    int colSize = board.getColSize();
    int rowSize = board.getRowSize();
    int diff = colSize - rowSize;

    if (diff >= 0) {
        for (int i = 0; i <= colSize - rowSize; ++i) {

            for (int v = 0; v <= rowSize - winNum; ++v) {
                bool allSame = true;
                int count = 0;

                // shifts search column from left to right one at a time
                for (int r = rowSize-1, c = 0; r >= v; --r, ++c) {
                    char curChar = board.at(r-v, c+i);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count >= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum) {
                    return true;
                }
            }
            for (int h = 0; h <= rowSize - winNum; ++h) {
                bool allSame = true;
                int count = 0;

                for (int r = rowSize - 1, c = 0; r >= h; --r, ++c) {
                    char curChar = board.at(r, c + h + i);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count >= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum) {
                    return true;
                }
            }
        }
        return false;
    }
    else {
        for (int i = 0; i <= rowSize - colSize; ++i) {

            for (int v = 0; v <= colSize - winNum; ++v) {
                bool allSame = true;
                int count = 0;

                // shifts search column from left to right one at a time
                for (int r = 0, c = colSize - 1; r < colSize-v; ++r, --c) {
                    char curChar = board.at(c+i-v, r);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count >= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum) {
                    return true;
                }
            }
            for (int h = 0; h <= colSize- winNum; ++h) {
                bool allSame = true;
                int count = 0;

                for (int r = 0, c = colSize-1; r < colSize-h; ++r, --c) {
                    char curChar = board.at(c+i, r+h);
                    if (curChar != firstChar) {
                        allSame = false;
                        count = 0;
                        continue;
                    }
                    ++count;
                    if (count >= winNum) {
                        break;
                    }
                }
                if (allSame || count >= winNum) {
                    return true;
                }
            }
        }
        return false;
    }
}

bool ConnectNGame::ConnectN::tie(int winNum) const {
    return !gameWon(winNum) && board.full();
}

void ConnectNGame::ConnectN::changeTurn() {
    playerTurn = (playerTurn + 1) % players.size();
}

void ConnectNGame::ConnectN::declareResults(int winNum) const {
    if (tie(winNum)) {
        std::cout << "Tie Game" << std::endl;
    } else {
        std::cout << getCurrentPlayer().getName() << " won the game!" << std::endl;
    }
}


