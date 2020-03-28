//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_MINE_HPP
#define PROJECT_MINE_HPP


#include "Holding.hpp"

class Mine: public Holding {

    string name;
    int cost;
    bool tapped;

    bool revealed;

    int harvestValue;
    Holding * upperHolding;         //null if it is not subHolding of other holding
    Holding * subHolding;           //null if it is not upperHolding of other holding

public:
    Mine(string n, int t, int spT);
    virtual ~Mine() {};
};


#endif //PROJECT_MINE_HPP
