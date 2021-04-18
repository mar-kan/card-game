//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_CARD_HPP
#define PROJECT_CARD_HPP

#include <istream>
#include <string>
#include <list>


using namespace std;

class Card {

public:                                                     //public so they can be used by the whole program
    enum Type{PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};
    enum Personalities{ATTACKER=1, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
    enum Holdings{PLAIN=1, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};
    enum Followers{FOOTSOLDIER=1, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
    enum Items{KATANA=1, SPEAR, BOW, NINJATO, WAKIZASHI};

private:
    string name;
    int cost;
    bool tapped;
    Type type;

public:
    Card(string, int);
    void PrintCardStats();
    virtual int effectBonus(int, int) { return 0; };
    virtual bool ChainHoldings(list<Card*>, Card*) { return false; };
    virtual ~Card() {};

    Type getType() const;
    void setTapped(bool tapped);
    bool isTapped() const;
    const string &getName() const;

    virtual int getCost() const;
};


#endif //PROJECT_CARD_HPP
