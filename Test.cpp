//
// Created by shira on 26/05/2020.
//

#include "doctest.h"

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;

TEST_CASE ("Board") {
    Board board1(8, 1);
    //OUT OF RANGE
            CHECK_THROWS((board1[{8, 0}]));
            CHECK_THROWS((board1[{9, 0}]));
            CHECK_THROWS((board1[{100, 23}]));
            CHECK_THROWS((board1[{5, 6}]));
            CHECK_THROWS((board1[{2, 1}]));
    //IN RANGE
            CHECK_NOTHROW((board1[{0, 0}]));
            CHECK_NOTHROW((board1[{2, 0}]));
            CHECK_NOTHROW((board1[{3, 0}]));
            CHECK_NOTHROW((board1[{4, 0}]));
            CHECK_NOTHROW((board1[{7, 0}]));

    Board board2(1, 1);
    //OUT OF RANGE
            CHECK_THROWS((board1[{1, 1}]));
    //IN RANGE
            CHECK_NOTHROW((board1[{0, 0}]));

    Board board3(8, 8);
            CHECK(!board3.has_soldiers(1));
            CHECK(!board3.has_soldiers(2));
}

TEST_CASE ("Placing the players on the board") {
    Board board(8, 8);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            //player 1
            int j1 = 0;
                    CHECK_NOTHROW((board[{i, j1}] = new FootSoldier(1)));
                    CHECK_THROWS((board[{i, j1}] = new FootSoldier(1)));
                    CHECK_NOTHROW((board[{i, ++j1}] = new FootSoldier(1)));
                    CHECK_THROWS((board[{i, j1}] = new FootSoldier(1)));
                    CHECK_NOTHROW((board[{i, ++j1}] = new Sniper(1)));
                    CHECK_THROWS((board[{i, j1}] = new Sniper(1)));
                    CHECK_NOTHROW((board[{i, ++j1}] = new Paramedic(1)));
                    CHECK_THROWS((board[{i, j1}] = new Paramedic(1)));
            //player 2
            int j2 = 0;
                    CHECK_NOTHROW((board[{7 - i, j2}] = new FootSoldier(2)));
                    CHECK_THROWS((board[{7 - i, j2}] = new FootSoldier(2)));
                    CHECK_NOTHROW((board[{7 - i, ++j2}] = new FootSoldier(2)));
                    CHECK_THROWS((board[{7 - i, j2}] = new FootSoldier(2)));
                    CHECK_NOTHROW((board[{7 - i, ++j2}] = new Sniper(2)));
                    CHECK_THROWS((board[{7 - i, j2}] = new Sniper(2)));
                    CHECK_NOTHROW((board[{7 - i, ++j2}] = new Paramedic(2)));
                    CHECK_THROWS((board[{7 - i, j2}] = new Paramedic(2)));
        }
    }
            CHECK_NOTHROW((board[{2, 2}] = new FootSoldier(1)));
            CHECK_THROWS((board[{2, 2}] = new FootSoldier(1)));
            CHECK_NOTHROW((board[{2, 4}] = new FootSoldier(1)));
            CHECK_THROWS((board[{2, 4}] = new FootSoldier(1)));
            CHECK_NOTHROW((board[{2, 6}] = new Sniper(1)));
            CHECK_THROWS((board[{2, 6}] = new Sniper(1)));
            CHECK_NOTHROW((board[{5, 2}] = new FootSoldier(2)));
            CHECK_THROWS((board[{5, 2}] = new FootSoldier(2)));
            CHECK_NOTHROW((board[{5, 4}] = new FootSoldier(2)));
            CHECK_THROWS((board[{5, 4}] = new FootSoldier(2)));
            CHECK_NOTHROW((board[{5, 6}] = new Sniper(2)));
            CHECK_THROWS((board[{5, 6}] = new Sniper(2)));

}

TEST_CASE ("Soldier") {
    Board board(6, 1);
    board[{0, 0}] = new FootSoldier(1);
    CHECK_EQ((board[{0, 0}]->health),100);
    CHECK_EQ((board[{0, 0}]->damage),10);
    board[{1, 0}] = new FootCommander(1);
    CHECK_EQ((board[{1, 0}]->health),150);
    CHECK_EQ((board[{1, 0}]->damage),20);
    board[{2, 0}] = new Sniper(1);
    CHECK_EQ((board[{2, 0}]->health),100);
    CHECK_EQ((board[{2, 0}]->damage),50);
    board[{3, 0}] = new SniperCommander(1);
    CHECK_EQ((board[{3, 0}]->health),120);
    CHECK_EQ((board[{3, 0}]->damage),100);
    board[{4, 0}] = new Paramedic(1);
    CHECK_EQ((board[{4, 0}]->health),100);
    board[{5, 0}] = new ParamedicCommander(1);
    CHECK_EQ((board[{5, 0}]->health),200);
}

TEST_CASE ("player 1 win!!") {
    Board board(8, 1);
    board[{0, 0}] = new FootSoldier(1);
    board[{7, 0}] = new FootSoldier(2);

    board.move(1, {0, 0}, Board::MoveDIR::Up);
    board.move(1, {1, 0}, Board::MoveDIR::Down);
    board.move(1, {0, 0}, Board::MoveDIR::Up);
    board.move(1, {1, 0}, Board::MoveDIR::Down);
    board.move(1, {0, 0}, Board::MoveDIR::Up);
    board.move(1, {1, 0}, Board::MoveDIR::Down);
    board.move(1, {0, 0}, Board::MoveDIR::Up);
    board.move(1, {1, 0}, Board::MoveDIR::Down);
    board.move(1, {0, 0}, Board::MoveDIR::Up);
    board.move(1, {1, 0}, Board::MoveDIR::Down);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}


