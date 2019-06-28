//
// Created by Joanna on 2019-05-01.
//

#ifndef CONNECTNGAME_CONNECTN_H
#define CONNECTNGAME_CONNECTN_H
#include <vector>
#include "Player.h"
#include "Board.h"
#include "Move.h"
namespace ConnectNGame {
    class ConnectN {

    public:
        explicit ConnectN(int row, int col);
        virtual ~ConnectN() = default;
        void play(int rowNum, int winNum);
        void determineStartingPlayer();
        Move getValidMove()const;

        const Player& getCurrentPlayer() const;
        Player& getCurrentPlayer();

        bool isGameOver(int winNum) const;
        bool gameWon(int winNum) const;
        bool horzWin(int winNum) const;
        bool vertWin(int winNum) const;
        bool diagWin(int winNum) const;
        bool leftDiagWin(int winNum) const;
        bool rightDiagWin(int winNum) const;
        bool tie(int winNum) const;

        void changeTurn();

        void declareResults(int winNum) const;

    private:
        Board board;
        std::vector<Player> players;
        int playerTurn;
    };
}

#endif //CONNECTNGAME_CONNECTN_H
