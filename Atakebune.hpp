//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_ATAKEBUNE_HPP
#define PROJECT_ATAKEBUNE_HPP

#include "Follower.hpp"

class Atakebune: public Follower {

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
    Atakebune(string n, int t, int spT);
    virtual ~Atakebune() {};
};


#endif //PROJECT_ATAKEBUNE_HPP
