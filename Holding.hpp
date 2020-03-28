//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_HOLDING_HPP
#define PROJECT_HOLDING_HPP

#include <string>
#include "BlackCard.hpp"

using namespace std;

class Deck;

class Holding: public BlackCard {

    string name;
    Holdings typeH;
    int cost;
    bool tapped;
    bool revealed;

    int harvestValue;
    Holding * upperHolding;         //null if it is not subHolding of other holding
    Holding * subHolding;           //null if it is not upperHolding of other holding

public:
    Holding(string n, int t, int spT, int c, int val);
    bool ChainHoldings(list<Card*>, Holding*) override;
    void PrintHolding();
    int getHoldingType();
    ~Holding() override;

    int getCost() const override;
    bool isTapped() const;
    int getHarvestValue() const override;
    Holding *getUpperHolding() const override;
    Holding *getSubHolding() const override;
    void setHarvestValue(int harvestValue);
    void setTapped(bool tapped);
    bool isRevealed() const;
    void setRevealed(bool revealed);
    void setUpperHolding(Holding *upperHolding) override;
    void setSubHolding(Holding *subHolding) override;

};


#endif //PROJECT_HOLDING_HPP
