//
// Created by shira on 26/05/2020.
//

#include "FootCommander.hpp"

void FootCommander::attack(std::vector<std::vector<Soldier *>>& board,std::pair<int,int> source) {
    Soldier* me = board[source.first][source.second];
    int player = me->player();
    FootSoldier::attack(board,source);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (me != board[i][j] && board[i][j]->player() == player) {
                    if (FootSoldier *mySoldier = dynamic_cast<FootSoldier *>(board[i][j])) {
                        std::pair<int, int> position = {i, j};
                        FootSoldier::attack(board, position);
                    }
                }
            }
        }
    }
}