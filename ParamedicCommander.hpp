//
// Created by shira on 26/05/2020.
//
#pragma once
#include "Paramedic.hpp"

class ParamedicCommander: public Paramedic{
public:
    ParamedicCommander(int player):Paramedic(player,200,0,200){}

    void attack(std::vector<std::vector<Soldier *>>&,std::pair<int,int> source) override;

};