//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_GREENCARD_HPP
#define PROJECT_GREENCARD_HPP

#include <string>
#include "Card.hpp"
using namespace std;


class GreenCard: public Card {

    string name;
    int cost;
    bool tapped;
    Type type;

    int attackBonus;
    int defenseBonus;
    int minimumHonor;
    string cardText;

    int effectBonus;
    int effectCost;

public:
    GreenCard(string n, int t);
    int addBonus(int, int);
    ~GreenCard() {/*nothing to delete*/};
};


#endif //PROJECT_GREENCARD_HPP
