//
// Created by shira on 26/05/2020.
//
#include "Paramedic.hpp"

void Paramedic::attack(std::vector<std::vector<Soldier*>>& board,std::pair<int,int> source){
    std::pair<int,int> attack;
    //First check where is the closest enemy soldier
    attack = Soldier::SearchEnemyToAttack(board,source,Filter::Close);
    if(attack.first == std::numeric_limits<int>::max()) return;
    if (board[attack.first][attack.second]== nullptr)return;
    //Attack
    board[attack.first][attack.second]->health() = board[attack.first][attack.second]->maxLife() ;
}