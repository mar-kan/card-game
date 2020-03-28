//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_GOLDMINE_HPP
#define PROJECT_GOLDMINE_HPP


#include "Holding.hpp"

class GoldMine: public Holding {

    string name;
    int cost;
    bool tapped;

    bool revealed;

    int harvestValue;
    Holding * upperHolding;         //null if it is not subHolding of other holding
    Holding * subHolding;           //null if it is not upperHolding of other holding

public:
    GoldMine(string n, int t, int spT);
    virtual ~GoldMine() {};
};


#endif //PROJECT_GOLDMINE_HPP
