//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_FOOTSOLDIER_HPP
#define PROJECT_FOOTSOLDIER_HPP


#include "Follower.hpp"

class Footsoldier: public Follower {

    string name;
    int cost;
    bool tapped;

    int attackBonus;
    int defenseBonus;
    int minimumHonor;
    int effectBonus;
    int effectCost;
    string cardText;

public:
    Footsoldier(string n, int t, int spT);
    ~Footsoldier() {};
};


#endif //PROJECT_FOOTSOLDIER_HPP
