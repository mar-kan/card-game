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
    virtual bool ChainHoldings(list<Card*>, Holding *) {};
    void PrintCardStats();
    virtual ~BlackCard() {};

    bool isTapped() const;
    bool isRevealed() const;
    const string &getName() const;

    //virtual getters and setters
    virtual int getCost() const {};
    virtual int getHonour() const {};

    void setTapped(bool tapped);
    void setRevealed(bool revealed);

    virtual int getHarvestValue() const {};
    virtual Holding *getUpperHolding() const {};
    virtual Holding *getSubHolding() const {};
    virtual void setUpperHolding(Holding *upperHolding) {};
    virtual void setSubHolding(Holding *subHolding) {};
};


#endif //PROJECT_BLACKCARD_HPP
