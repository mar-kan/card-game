//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_FARMLAND_HPP
#define PROJECT_FARMLAND_HPP

#include "Holding.hpp"

class Farmland: public Holding {

    string name;
    int cost;
    bool tapped;

    bool revealed;

    int harvestValue;
    const Holding * upperHolding = nullptr;         //null always
    const Holding * subHolding = nullptr;           //null always

public:
    Farmland(string n, int t, int spT);
    virtual ~Farmland() {};
};


#endif //PROJECT_FARMLAND_HPP
