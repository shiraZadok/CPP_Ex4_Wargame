//
// Created by shira on 26/05/2020.
//
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
    enum MoveDIR { Up, Down, Right, Left };

    Board(uint numRows, uint numCols) :
            board(numRows, std::vector<Soldier*>(numCols, nullptr)) {}
    Soldier*& operator[](std::pair<int,int> location){return board[location.first][location.second];}
    Soldier* operator[](std::pair<int,int> location) const{ Soldier *s; return s;}
    void move(uint player_number, std::pair<int,int> source, MoveDIR direction){}
    bool has_soldiers(uint player_number) const{return false;}
    ~Board(){
        board.clear();
    }
};
