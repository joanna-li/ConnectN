//
// Created by Joanna on 2019-05-01.
//

#ifndef CONNECTNGAME_BOARD_H
#define CONNECTNGAME_BOARD_H

#include <vector>
#include <string>
namespace ConnectNGame {
    class Board {
    public:
        using iterator = std::vector<std::string>::iterator;
        using const_iterator = std::vector<std::string>::const_iterator;


        explicit Board(int row, int col, char blankSpace);
        int getRowSize() const;
        int getColSize() const;
        int getFirstAvailableRowNo(int col) const;
        void display(int rowNum) const;
        bool inBounds(int col) const;
        bool isBlankSpace(int row, int col) const;
        bool isBlankSpace2(int col) const;
        bool checkAvailableRow(int col) const;
        void set(int col, char val);
        int rowPosition(int col) const;

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        const char& at(int row, int col) const;

        const char getblankSpace() const;
        bool full() const;

    private:
        static bool isBetween(int val, int lower, int upper);

    private:
        std::vector<std::string> boardState;
        const char blankSpace;

    };
}

#endif //CONNECTNGAME_BOARD_H
