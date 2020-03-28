//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_KATANA_HPP
#define PROJECT_KATANA_HPP


#include "Item.hpp"

class Katana: public Item {

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
    Katana(string n, int t, int spT);
    virtual ~Katana() {};
};


#endif //PROJECT_KATANA_HPP
