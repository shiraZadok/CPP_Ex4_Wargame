//
// Created by shira on 26/05/2020.
//
#pragma once
#include "Sniper.hpp"

class SniperCommander: public Sniper{
public:
    SniperCommander(int player):Sniper(player,120,100,120){}

    void attack(std::vector<std::vector<Soldier *>>&,std::pair<int,int> source) override;
};