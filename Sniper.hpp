//
// Created by shira on 26/05/2020.
//
#pragma once
#include "Soldier.hpp"

class Sniper: public Soldier{
public:
    Sniper(int player,int health=100,int damage =50, int maxLife=100):Soldier(player,health,damage,maxLife){}

    void attack(std::vector<std::vector<Soldier *>>&,std::pair<int,int> source) override;
};