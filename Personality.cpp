//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "Personality.hpp"
#include "Defender.hpp"
#include "Attacker.hpp"
#include "Shogun.hpp"
#include "Chancellor.hpp"
#include "Champion.hpp"


Personality::Personality(string n, int t, int spT, int c, int at, int def, int hon, int mf, int mi) : BlackCard{n, t}
{
    name = n;
    typeP = Personalities(spT);

    cost = c;

    tapped = false;
    revealed = false;

    attack = at;
    defense = def;
    honour = hon;

    dead = false;

    maxFollowers = mf;
    maxItems = mi;
}


bool Personality::PushGreenCard(GreenCard * card)                   //pushes new item or follower
{
    if (card->getType() == FOLLOWER)
    {
        if (followers.size() >= maxFollowers)
            return false;

        Follower * newFollow = reinterpret_cast<Follower*>(card);
        followers.push_back(newFollow);
    }
    else
    {
        if (items.size() >= maxItems)
            return false;

        Item * newItem = reinterpret_cast<Item*>(card);
        items.push_back(newItem);
    }
    return true;
}


int Personality::getPersonalityType()                               //returns int that corresponds to Personalities enum
{
    return Personalities(typeP);
}


void Personality::PrintPersonality()                                //prints personality's card stats
{
    cout << "Card: " << name << endl;
    cout << "Cost: " << cost << endl;

    cout << "Personality Type: ";
    if (typeP == ATTACKER)
        cout << "Attacker" << endl;
    else if (typeP == DEFENDER)
        cout << "Defender" << endl;
    else if (typeP == SHOGUN)
        cout << "Shogun" << endl;
    else if (typeP == CHANCELLOR)
        cout << "Chancellor" << endl;
    else if (typeP == CHAMPION)
        cout << "Champion" << endl;
    else
        return;

    if (tapped)
        cout << "Tapped: yes" << endl;
    else
        cout << "Tapped: no" << endl;

    if (revealed)
        cout << "Revealed: yes" << endl;
    else
        cout << "Revealed: no" << endl;

    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Honour: " << honour << endl;

    cout << "Maximum possible followers: " << maxFollowers << endl;

    list<Follower*>::iterator itf;

    if (followers.empty())
        cout << "No followers" << endl;
    else
    {
        for (itf=followers.begin(); itf!=followers.end(); itf++)
            (*itf)->PrintFollower();
    }

    cout << "Maximum possible items: " << maxItems << endl;

    list<Item*>::iterator iti;

    if (items.empty())
        cout << "No followers" << endl;
    else
    {
        for (iti=items.begin(); iti!=items.end(); iti++)
            (*iti)->PrintItem();
    }
    cout << endl;
}

void Personality::PersonalityConsequences()
{
    list<Follower*>::iterator itf;
    if (!followers.empty())
    {
        for (itf=followers.begin(); itf!=followers.end(); itf++)
            (*itf)->setTapped(true);
    }

    list<Item*>::iterator iti;
    if (!items.empty())
    {
        for (iti=items.begin(); iti!=items.end(); iti++)
            (*iti)->setDurability((*iti)->getDurability()-1);
    }
}


Personality::~Personality()
{
    list<Follower*>::iterator itf;
    for (itf = followers.begin(); itf != followers.end(); itf++)
    {
        followers.remove((*itf));
        delete *itf;
        itf = followers.begin();
    }

    list<Item*>::iterator iti;
    for (iti = items.begin(); iti != items.end(); iti++)
    {
        items.remove((*iti));
        delete *iti;
        iti = items.begin();
    }
}


//getters
bool Personality::isTapped() const
{
    return tapped;
}


bool Personality::isRevealed() const
{
    return revealed;
}


int Personality::getCost() const
{
    return cost;
}


int Personality::getAttack() const
{
    return attack;
}


int Personality::getDefense() const
{
    return defense;
}


int Personality::getHonour() const
{
    return honour;
}


int Personality::getMaxFollowers() const
{
    return maxFollowers;
}


int Personality::getMaxItems() const
{
    return maxItems;
}


//setters
void Personality::setTapped(bool tapped)
{
    Personality::tapped = tapped;
}


void Personality::setRevealed(bool revealed)
{
    Personality::revealed = revealed;
}