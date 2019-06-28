#include <iostream>
#include <string>
#include "ConnectN.h"

using namespace std;

int main(int argc, char**argv) {
    ConnectNGame::ConnectN game(stoi(argv[1]), stoi(argv[2]));
    game.play(stoi(argv[1]), stoi(argv[3]));

    return 0;

}