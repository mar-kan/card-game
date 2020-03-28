//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_FOLLOWER_HPP
#define PROJECT_FOLLOWER_HPP


#include <string>
#include "GreenCard.hpp"
using namespace std;


class Follower: public GreenCard {

    string name;
    int cost;
    bool tapped;
    Followers typeF;

    int attackBonus;
    int defenseBonus;
    int minimumHonor;
    string cardText;

    int effectBonus;
    int effectCost;

public:
    Follower(string n, int t, int spT, int cost, int at, int def, int hon, int bon, int bc, string txt);
    void PrintFollower();
    int getFollowerType();
    virtual ~Follower() {};

    int getCost() const;
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
};


#endif //PROJECT_FOLLOWER_HPP
