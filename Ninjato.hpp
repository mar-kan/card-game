//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_NINJATO_HPP
#define PROJECT_NINJATO_HPP


#include "Item.hpp"

class Ninjato: public Item {

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
    Ninjato(string n, int t, int spT);
    virtual ~Ninjato() {};
};


#endif //PROJECT_NINJATO_HPP
