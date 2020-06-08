//
// Created by shira on 26/05/2020.
//
#pragma once
#include "FootSoldier.hpp"

class FootCommander: public FootSoldier{
public:
    FootCommander(int player) : FootSoldier(player, 150, 20,150) {}

    void attack(std::vector<std::vector<Soldier *>>&,std::pair<int,int> source) override;
};