//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_BLACKCARD_HPP
#define PROJECT_BLACKCARD_HPP

#include <string>
#include "Card.hpp"

class Holding;

using namespace std;

class BlackCard: public Card {

    string name;
    int cost;
    bool tapped;
    Type type;

    bool revealed;

public:
    BlackCard(string n, int t);
    virtual bool ChainHoldings(list<Card*>, Holding *) { return false; };
    void PrintCardStats();
    virtual ~BlackCard() {};

    bool isTapped() const;
    bool isRevealed() const;
    const string &getName() const;

    //virtual getters and setters
    virtual int getCost() const { return 0; };
    virtual int getHonour() const { return 0; };

    void setTapped(bool tapped);
    void setRevealed(bool revealed);

    virtual int getHarvestValue() const { return 0; };
    virtual Holding *getUpperHolding() const { return nullptr; };
    virtual Holding *getSubHolding() const { return nullptr; };
    virtual void setUpperHolding(Holding *upperHolding) {};
    virtual void setSubHolding(Holding *subHolding) {};
};


#endif //PROJECT_BLACKCARD_HPP
