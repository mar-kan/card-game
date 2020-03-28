//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_PERSONALITY_HPP
#define PROJECT_PERSONALITY_HPP

#include <string>
#include <list>
#include "BlackCard.hpp"
#include "Follower.hpp"
#include "Item.hpp"
using namespace std;


class Personality: public BlackCard {

    string name;
    Personalities typeP;
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
    Personality(string n, int t, int spT, int c, int at, int def, int hon, int mf, int mi);
    bool PushGreenCard(GreenCard *);
    void PrintPersonality();
    int getPersonalityType();
    void PersonalityConsequences();
    ~Personality() override;

    bool isTapped() const;
    bool isRevealed() const;
    int getCost() const override;
    int getAttack() const;
    int getDefense() const;
    int getHonour() const override;
    int getMaxFollowers() const;
    int getMaxItems() const;
    void setTapped(bool tapped);
    void setRevealed(bool revealed);
};


#endif //PROJECT_PERSONALITY_HPP
