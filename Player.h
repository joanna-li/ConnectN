//
// Created by Joanna on 2019-05-01.
//

#ifndef CONNECTNGAME_PLAYER_H
#define CONNECTNGAME_PLAYER_H

#include <string>
namespace ConnectNGame{
    class Player {
    public:
        Player();
        const std::string& getName() const;
        char getPiece() const;
        bool validName(std::string name);
        bool validPiece(char piece);
        static int counter;
        static std::string previousName;
        static char previousPiece;

    private:
        std::string name;
        char piece;
    };
}

#endif //CONNECTNGAME_PLAYER_H
