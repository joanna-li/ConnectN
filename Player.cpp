//
// Created by Joanna on 2019-05-01.
//

#include <iostream>
#include <string>
#include "Player.h"

ConnectNGame::Player::Player() {

    do {
        std::cout << "Player " << counter << ", please enter your name: ";
        std::cin >> name;
        std::string extra;
        std::getline(std::cin, extra);
    } while (!ConnectNGame::Player::validName(name));
    previousName = name;

    do {
        std::cout << name << ", please enter the character you want to use for your piece: ";
        std::cin >> piece;
        std::string discard;
        std::getline(std::cin, discard);
    } while (!ConnectNGame::Player::validPiece(piece));
    previousPiece = piece;
    ++counter;
}



const std::string& ConnectNGame::Player::getName() const {
    return name;
}

char ConnectNGame::Player::getPiece() const {
    return piece;
}

int ConnectNGame::Player::counter = 1;

std::string ConnectNGame::Player::Player::previousName = "";

char ConnectNGame::Player::previousPiece = ' ';

bool ConnectNGame::Player::validName(std::string name) {
    bool isSame = true;
    if (name.empty() || previousName == name)
        isSame = false;
    for (int i = 0; i < name.length(); i++)
        if (isalpha(name[i]) == false)
            isSame = false;
    return isSame;
}

bool ConnectNGame::Player::validPiece(char piece) {
    bool isSame = true;
    if (isalpha(piece) == false || previousPiece == piece)
        isSame = false;
    return isSame;
}