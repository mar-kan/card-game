//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_CHAMPION_HPP
#define PROJECT_CHAMPION_HPP


#include "Personality.hpp"

class Champion: public Personality {

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
    Champion(string n, int t, int spT);
    virtual ~Champion() {};
};


#endif //PROJECT_CHAMPION_HPP
