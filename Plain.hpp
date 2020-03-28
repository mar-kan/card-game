//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_PLAIN_HPP
#define PROJECT_PLAIN_HPP


#include "Holding.hpp"

class Plain: public Holding {

    string name;
    int cost;
    bool tapped;
    bool revealed;

    int harvestValue;
    const Holding * upperHolding = nullptr;         //null always
    const Holding * subHolding = nullptr;           //null always

public:
    Plain(string n, int t, int spT);
    virtual ~Plain() {};
};


#endif //PROJECT_PLAIN_HPP