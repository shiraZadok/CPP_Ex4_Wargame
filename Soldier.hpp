//
// Created by shira on 26/05/2020.
//
#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include<bits/stdc++.h>

enum Filter {Life, Close};

class Soldier{
protected:
    int Player;
    int Health;
    int Damage;
    int MaxLife;

public:
//    Soldier(){}
    Soldier (int player, int health, int damage,int maxLife):Player(player),Health(health), Damage(damage),MaxLife(maxLife){}

    virtual void attack(std::vector<std::vector<Soldier*>>&, std::pair<int,int>)= 0;

    //getter & setter
    int& health(){return Health;}

    //getter & setter
    int& damage(){return Damage;}

    //getter
    const int& player(){return Player;}

    //getter & setter
    int& maxLife(){return MaxLife;}

    std::pair<int,int> SearchEnemyToAttack(std::vector<std::vector<Soldier*>>&,std::pair<int,int>,Filter);

    virtual ~Soldier() {};
};
