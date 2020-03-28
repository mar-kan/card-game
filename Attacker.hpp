//Kanellaki Maria Anna - 1115201400060
//Matanis Paganiotis - 1115201400297


#ifndef PROJECT_ATTACKER_HPP
#define PROJECT_ATTACKER_HPP

#include "Personality.hpp"

class Attacker: public Personality {

    string name;
    int cost;
    bool tapped;

    bool revealed;

    int attack;
    int defense;
    int honour;
    bool dead;

    int maxFollowers;
    list<Follower*> followers;

    int maxItems;
    list<Item*> items;


public:
    Attacker(string n, int t, int spT);
    virtual ~Attacker() {};
};


#endif //PROJECT_ATTACKER_HPP
