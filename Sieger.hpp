//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_SIEGER_HPP
#define PROJECT_SIEGER_HPP


#include "Follower.hpp"

class Sieger: public Follower {

    string name;
    int cost;
    bool tapped;

    int attackBonus;
    int defenseBonus;
    int minimumHonor;
    string cardText;

    int effectBonus;
    int effectCost;

public:
    Sieger(string n, int t, int spT);
    virtual ~Sieger() {};
};


#endif //PROJECT_SIEGER_HPP
