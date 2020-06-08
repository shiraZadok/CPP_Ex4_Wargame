//
// Created by shira on 26/05/2020.
//
#include "Sniper.hpp"

void Sniper::attack(std::vector<std::vector<Soldier*>>& board,std::pair<int,int> source){
    std::pair<int,int> attack;
    //First check where is the closest enemy soldier
    attack = Soldier::SearchEnemyToAttack(board,source,Filter::Life);
    //Attack
    if(attack.first == std::numeric_limits<int>::max()) return;
    if (board[attack.first][attack.second]== nullptr)return;
    board[attack.first][attack.second]->health() =board[attack.first][attack.second]->health() - board[source.first][source.second]->damage();
    if (board[attack.first][attack.second]->health()<= 0) {
        delete board[attack.first][attack.second];
        board[attack.first][attack.second] = nullptr;
    }
}