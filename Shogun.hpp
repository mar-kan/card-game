//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_SHOGUN_HPP
#define PROJECT_SHOGUN_HPP


#include "Personality.hpp"

class Shogun: public Personality {

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
    Shogun(string n, int t, int spT);
    virtual ~Shogun() {};
};


#endif //PROJECT_SHOGUN_HPP
