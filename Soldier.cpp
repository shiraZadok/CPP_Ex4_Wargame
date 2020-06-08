//
// Created by shira on 26/05/2020.
//
#include "Soldier.hpp"

std::pair<int,int> Soldier::SearchEnemyToAttack(std::vector<std::vector<Soldier*>>& board,std::pair<int,int> source,Filter option){
    int player = board[source.first][source.second]->player();
    int minResult= INT_MAX;
    std::pair<int, int> posSoldierToAttack;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr && board[i][j]->player() != player) {
                int result =  Filter::Close == option? sqrt(abs(i - source.first) + abs(j - source.second))
                        : (-1)*board[i][j]->health();
                if (result < minResult) {
                    minResult = result;
                    posSoldierToAttack.first = i;
                    posSoldierToAttack.second = j;
                }
            }
        }
    }
    return posSoldierToAttack;
}