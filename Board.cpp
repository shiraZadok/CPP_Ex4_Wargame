//
// Created by shira on 26/05/2020.
//
#include <vector>
#include "Board.hpp"
using namespace WarGame;
using namespace std;

void Board::move(int player_number, std::pair<int,int> source, MoveDIR direction){
    if(source.first<0 ||source.first>=board.size()||source.second<0||source.second>=board[source.first].size())
        throw std::invalid_argument("This location is out of bound");
    Soldier* play = (*this)[source];
    std::pair<int,int> target;
    if (board[source.first][source.second]== nullptr)
        throw std::invalid_argument("There no soldier in this location");
    if (board[source.first][source.second]->player()!=player_number)
        throw std::invalid_argument("This is not your soldier");

    switch (direction) {
        case Board::MoveDIR::Up:
            target={source.first+1,source.second};
            break;
        case Board::MoveDIR::Down:
            target={source.first-1,source.second};
            break;
        case Board::MoveDIR::Right:
            target={source.first,source.second+1};
            break;
        case Board::MoveDIR::Left:
            target={source.first,source.second-1};
            break;
    }
    if(target.first<0 ||target.first>=board.size()||target.second<0||target.second>=board[target.first].size())
        throw std::invalid_argument("This location is out of bound");
    if(board[target.first][target.second]!= nullptr)
        throw std::invalid_argument("There is already a soldier in this location");
    (*this)[target]=play;
    (*this)[source]= nullptr;
    play->attack(board,target);
}

bool Board::has_soldiers(int player_number) const{
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++){
            if(board[i][j]!= nullptr&&board[i][j]->player()==player_number)
                return true;
        }
    }
    return false;
}