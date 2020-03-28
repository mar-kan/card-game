//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_CHANCELLOR_HPP
#define PROJECT_CHANCELLOR_HPP


#include "Personality.hpp"

class Chancellor: public Personality {

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
    list<Follower*>::iterator itf;

    int maxItems;
    list<Item*> items;
    list<Item*>::iterator iti;

public:
    Chancellor(string n, int t, int spT);
    virtual ~Chancellor() {};
};


#endif //PROJECT_CHANCELLOR_HPP
