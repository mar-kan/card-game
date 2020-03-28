//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_CRYSTALMINE_HPP
#define PROJECT_CRYSTALMINE_HPP


#include "Holding.hpp"

class CrystalMine: public Holding {

    string name;
    int cost;
    bool tapped;

    bool revealed;

    int harvestValue;
    Holding * upperHolding;         //null if it is not subHolding of other holding
    Holding * subHolding;           //null if it is not upperHolding of other holding

public:
    CrystalMine(string n, int t, int spT);
    virtual ~CrystalMine() {};
};


#endif //PROJECT_CRYSTALMINE_HPP
