//
// Created by Joanna on 2019-05-01.
//

#ifndef CONNECTNGAME_MOVE_H
#define CONNECTNGAME_MOVE_H
#include <sstream>
#include "Player.h"
#include "Board.h"
namespace ConnectNGame {

    class Move {
    public:
        Move(const Player& maker);
        void parseInput(std::stringstream& input);
        bool isValid(const Board& board) const;
        void make(Board& board);
    private:
        const Player& maker;
        int row, col;
        bool parsedSuccessfully;

    };
}

#endif //CONNECTNGAME_MOVE_H
