//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "Follower.hpp"
#include "Footsoldier.hpp"
#include "Archer.hpp"
#include "Sieger.hpp"
#include "Cavalry.hpp"
#include "Atakebune.hpp"
#include "Bushido.hpp"


Follower::Follower(string n, int t, int spT, int c, int at, int def, int hon, int bon, int bc, string txt) : GreenCard{n, t}
{
    name = n;
    typeF = Followers(spT);
    tapped = false;

    cost = c;
    attackBonus = at;
    defenseBonus = def;
    minimumHonor = hon;
    cardText = txt;

    effectBonus = bon;
    effectCost = bc;
}


int Follower::getFollowerType()                 //returns int that corresponds to Followers enum
{
    return Followers(typeF);
}


void Follower::PrintFollower()                  //prints card stats
{
    cout << "Card: " << name << endl;
    cout << "Cost: " << getCost() << endl;

    cout << "Follower Type: ";
    if (typeF == FOOTSOLDIER)
        cout << "Footsoldier"<< endl;
    else if (typeF == ARCHER)
        cout << "Archer"<< endl;
    else if (typeF == SIEGER)
        cout << "Sieger"<< endl;
    else if (typeF == CAVALRY)
        cout << "Cavalry"<< endl;
    else if (typeF == NAVAL)
        cout << "Atakebune"<< endl;
    else if (typeF == BUSHIDO)
        cout << "Bushido"<< endl;
    else
        return;

    if (tapped)
        cout << "Tapped: yes"<<endl;
    else
        cout <<"Tapped: no"<<endl;

    cout << "Attack: " << getAttackBonus() << endl;
    cout << "Defense: " << getDefenseBonus() << endl;
    cout << "Minimum Honor Required: " << getMinimumHonor() << endl;

    cout << "Effect Bonus: " << getEffectBonus() << endl;
    cout << "Effect Cost: " << getEffectCost() << endl;

    cout << "Card text: " << getCardText() << endl;
    cout << endl;
}


//getters
int Follower::getCost() const
{
    return cost;
}

bool Follower::isTapped() const
{
    return tapped;
}


int Follower::getEffectBonus() const
{
    return effectBonus;
}


int Follower::getEffectCost() const
{
    return effectCost;
}


int Follower::getAttackBonus() const
{
    return attackBonus;
}


int Follower::getDefenseBonus() const
{
    return defenseBonus;
}


int Follower::getMinimumHonor() const
{
    return minimumHonor;
}


const string &Follower::getCardText() const
{
    return cardText;
}


//setters
void Follower::setAttackBonus(int attackBonus)
{
    Follower::attackBonus = attackBonus;
}


void Follower::setDefenseBonus(int defenseBonus)
{
    Follower::defenseBonus = defenseBonus;
}


void Follower::setTapped(bool tapped)
{
    Follower::tapped = tapped;
}
