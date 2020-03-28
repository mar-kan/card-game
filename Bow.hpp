//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_BOW_HPP
#define PROJECT_BOW_HPP


#include "Item.hpp"

class Bow: public Item {

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
    Bow(string n, int t, int spT);
    virtual ~Bow() {};
};


#endif //PROJECT_BOW_HPP
