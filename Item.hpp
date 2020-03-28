//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_ITEM_HPP
#define PROJECT_ITEM_HPP

#include <string>
#include "GreenCard.hpp"
using namespace std;

class Item: public GreenCard {

    string name;
    Items typeI;
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
    Item(string n, int t, int spT, int c, int at, int def, int hon, int bon, int bc, int d, string txt);
    void PrintItem();
    int getItemType();
    virtual ~Item() {};

    int getCost() const override;
    bool isTapped() const;
    int getEffectBonus() const;
    int getEffectCost() const;
    void setAttackBonus(int attackBonus);
    void setDefenseBonus(int defenseBonus);
    int getAttackBonus() const;
    int getDefenseBonus() const;
    int getMinimumHonor() const;
    void setTapped(bool tapped);
    const string &getCardText() const;
    void setDurability(int durability);
    int getDurability() const;
};


#endif //PROJECT_ITEM_HPP
