//
// Created by shira on 26/05/2020.
//
#pragma once
#include <sys/types.h>
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame {
    class Board;
}

class WarGame::Board {
private:
    std::vector<std::vector<Soldier*>> board;

public:
    enum MoveDIR { Up , Down , Right , Left };
    Board(int numRows, int numCols) :
            board(numRows, std::vector<Soldier*>(numCols, nullptr)) {}

    // operator for putting soldiers on the game-board during initialization.
    Soldier*& operator[](std::pair<int,int> location){
            return board[location.first][location.second];
    }

    // operator for reading which soldiers are on the game-board.
    Soldier* operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }

    void move(int player_number, std::pair<int,int> source, MoveDIR direction);

    bool has_soldiers(int player_number) const;

    ~Board(){
        board.clear();
    }
};
