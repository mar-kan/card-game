//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_BUSHIDO_HPP
#define PROJECT_BUSHIDO_HPP

#include "Follower.hpp"

class Bushido: public Follower {

    string name;
    int cost;
    bool tapped;

    int attackBonus;
    int defenseBonus;
    int minimumHonor;
    string cardText;

    int effectCost;
    int effectBonus;

public:
    Bushido(string n, int t, int spT);
    ~Bushido() {};
};


#endif //PROJECT_BUSHIDO_HPP
