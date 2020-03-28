//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_ARCHER_HPP
#define PROJECT_ARCHER_HPP

#include "Follower.hpp"

class Archer: public Follower {

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
    Archer(string n, int t, int spT);
    virtual ~Archer() {};
};


#endif //PROJECT_ARCHER_HPP
