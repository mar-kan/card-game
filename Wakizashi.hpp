//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_WAKIZASHI_HPP
#define PROJECT_WAKIZASHI_HPP


#include "Item.hpp"

class Wakizashi: public Item {

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
    Wakizashi(string n, int t, int spT);
    virtual ~Wakizashi() {};
};


#endif //PROJECT_WAKIZASHI_HPP
