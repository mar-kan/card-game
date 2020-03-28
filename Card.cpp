//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "Card.hpp"
#include "Follower.hpp"
#include "Item.hpp"
#include "Personality.hpp"
#include "Holding.hpp"

Card::Card(string n, int t)
{
    name = n;
    tapped = false;
    type = Type(t);
}


void Card::PrintCardStats()                                 //defines type of card and calls proper print function for that type
{
    if (type == FOLLOWER)
    {
        Follower * fol = reinterpret_cast<Follower *> (this);
        fol->PrintFollower();

        fol = nullptr;
        delete fol;
    }
    else if (type == ITEM)
    {
        Item * item = reinterpret_cast<Item *> (this);
        item->PrintItem();

        item = nullptr;
        delete item;
    }
    else if (type == PERSONALITY)
    {
        Personality* pers = reinterpret_cast<Personality*> (this);
        pers->PrintPersonality();

        pers = nullptr;
        delete pers;
    }
    else if (type == HOLDING)
    {
        Holding * hold = reinterpret_cast<Holding*>(this);
        hold->PrintHolding();

        hold = nullptr;
        delete hold;
    }
    else
        exit(-1);
}


//getters
Card::Type Card::getType() const
{
    return type;
}


bool Card::isTapped() const
{
    return tapped;
}


const string &Card::getName() const
{
    return name;
}


int Card::getCost() const
{
    return cost;
}


//setters
void Card::setTapped(bool tapped)
{
    Card::tapped = tapped;
}


