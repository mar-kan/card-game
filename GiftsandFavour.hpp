//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_GIFTSANDFAVOUR_HPP
#define PROJECT_GIFTSANDFAVOUR_HPP


#include "Holding.hpp"

class GiftsandFavour: public Holding {

    string name;
    int cost;
    bool tapped;

    bool revealed;

    int harvestValue;
    const Holding * upperHolding = nullptr;         //null always
    const Holding * subHolding = nullptr;           //null always

public:
    GiftsandFavour(string n, int t, int spT);
    virtual ~GiftsandFavour() {};
};


#endif //PROJECT_GIFTSANDFAVOUR_HPP
