//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_DEFENDER_HPP
#define PROJECT_DEFENDER_HPP


#include "Personality.hpp"

class Defender: public Personality {

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
    Defender(string n, int t, int spT);
    virtual ~Defender() {};
};


#endif //PROJECT_DEFENDER_HPP
