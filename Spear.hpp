//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_SPEAR_HPP
#define PROJECT_SPEAR_HPP


#include "Item.hpp"

class Spear: public Item {

    string name;
    int cost;
    bool tapped;

    int attackBonus;
    int defenseBonus;
    int minimumHonor;
    string cardText;

    int effectBonus;
    int effectCost;

    int durability;

public:
    Spear(string n, int t, int spT);
    virtual ~Spear() {};
};


#endif //PROJECT_SPEAR_HPP
