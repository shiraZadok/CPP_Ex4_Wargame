//
// Created by shira on 26/05/2020.
//

#include "ParamedicCommander.hpp"

void ParamedicCommander::attack(std::vector<std::vector<Soldier *>>& board,std::pair<int,int> source) {
    Soldier* me = board[source.first][source.second];
    int player = me->player();
    Paramedic::attack(board,source);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (me != board[i][j] && board[i][j]->player() == player) {
                    if (Paramedic *mySoldier = dynamic_cast<Paramedic *>(board[i][j])) {
                        std::pair<int, int> position = {i, j};
                        Paramedic::attack(board, position);
                    }
                }
            }
        }
    }
}