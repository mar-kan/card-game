//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_CAVALRY_HPP
#define PROJECT_CAVALRY_HPP


#include "Follower.hpp"

class Cavalry: public Follower {

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
    Cavalry(string n, int t, int spT);
    ~Cavalry() {};
};


#endif //PROJECT_CAVALRY_HPP
