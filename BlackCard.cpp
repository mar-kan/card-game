//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "BlackCard.hpp"
#include "Personality.hpp"
#include "Holding.hpp"

BlackCard::BlackCard(string n, int t): Card{n, t}
{
    name = n;

    tapped = false;
    revealed = false;
    type = Type(t);
}


void BlackCard::PrintCardStats()                                //defines type of card and calls proper print function for that type
{
    if (type == PERSONALITY)
    {
        Personality* pers = reinterpret_cast<Personality*>(this);
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
bool BlackCard::isRevealed() const
{
    return revealed;
}


bool BlackCard::isTapped() const
{
    return tapped;
}


const string &BlackCard::getName() const
{
    return name;
}


//setters
void BlackCard::setRevealed(bool revealed)
{
    BlackCard::revealed = revealed;
}


void BlackCard::setTapped(bool tapped)
{
    BlackCard::tapped = tapped;
}