//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "Holding.hpp"
#include "Deck.hpp"
#include "Plain.hpp"
#include "GiftsandFavour.hpp"
#include "Mine.hpp"
#include "GoldMine.hpp"
#include "CrystalMine.hpp"
#include "Farmland.hpp"


Holding::Holding(string n, int t, int spT, int c, int val): BlackCard{n, t}
{
    name = n;
    typeH = Holdings(spT);

    tapped = false;
    revealed = false;

    cost = c;
    harvestValue = val;

    subHolding = nullptr;
    upperHolding = nullptr;
}


bool Holding::ChainHoldings(list<Card*> holdings, Holding *bought)        //creates chains and adds bonuses if there are any possible connections
{
    if (bought->getName() != "Mine" && bought->getName() != "GoldMine" && bought->getName() != "CrystalMine")
        return false;

    list<Card*>::iterator it;

    if (bought->getName() == "Mine")
    {
        for (it=holdings.begin(); it!=holdings.end(); it++)
        {
            if ((*it)->getName() != "GoldMine")
                continue;

            Holding *mine = (Holding *)(&*it);

            if (!mine->getSubHolding())
            {
                mine->setSubHolding(bought);
                bought->setUpperHolding(mine);

                if (mine->getUpperHolding())
                {
                    mine->harvestValue *= 2;
                    mine->upperHolding->harvestValue *= 3;
                }
                else
                {
                    mine->harvestValue += 4;
                    bought->harvestValue += 2;
                }
                return true;
            }
        }
    }
    else if (bought->getName() == "GoldMine")
    {
        for (it=holdings.begin(); it!=holdings.end(); it++)
        {
            if ((*it)->getName() == "Mine")
            {
                Holding *mine = (Holding *)(&*it);

                if (!mine->getUpperHolding())
                {
                    mine->setUpperHolding(bought);
                    bought->setSubHolding(mine);

                    bought->harvestValue += 4;
                    mine->harvestValue += 2;
                }
            }
            else if ((*it)->getName() == "CrystalMine")
            {
                Holding *mine = (Holding *)(&*it);

                if (!mine->getSubHolding())
                {
                    mine->setSubHolding(bought);
                    bought->setUpperHolding(mine);

                    bought->harvestValue += 5;
                    mine->harvestValue += harvestValue;
                }
            }
            
            if (bought->getSubHolding() && bought->getUpperHolding())
                return true;
        }
        if (bought->getSubHolding() || bought->getUpperHolding())
            return true;
    }
    else if (bought->getName() == "CrystalMine")
    {
        for (it=holdings.begin(); it!=holdings.end(); it++)
        {
            if ((*it)->getName() != "GoldMine")
                continue;

            Holding *mine = (Holding *)(&*it);

            if (!mine->getUpperHolding())
            {
                mine->setUpperHolding(bought);
                bought->setSubHolding(mine);

                if (mine->getSubHolding())
                {
                    mine->harvestValue *= 2;
                    mine->upperHolding->harvestValue *= 3;
                }
                else
                {
                    bought->harvestValue += 5;
                    mine->harvestValue += 3;    //3 = initial mine harvest value
                }
                break;
            }
        }
    }
    return true;
}


int Holding::getHoldingType()                 //returns int that corresponds to Holdings enum
{
    return Holdings(typeH);
}


void Holding::PrintHolding()                  //prints holding's card stats
{
    cout << "Card: " << name << endl;
    cout << "Cost: " << getCost() << endl;

    cout << "Holding Type: ";
    if (typeH == PLAIN)
        cout << "Plain" << endl;
    else if (typeH == MINE)
        cout << "Mine" << endl;
    else if (typeH == GOLD_MINE)
        cout << "Gold Mine" << endl;
    else if (typeH == CRYSTAL_MINE)
        cout << "Crystal Mine" << endl;
    else if (typeH == FARMS)
        cout << "Farms" << endl;
    else if (typeH == SOLO)
        cout << "Gifts and Favour" << endl;
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

    cout << "Harvest Value: " << getHarvestValue() << endl;

    if (!upperHolding && !subHolding)
    {
        cout << "Holding is not in a chain" << endl << endl;
        return;
    }
    if (upperHolding && subHolding)
        cout << "Holding in complete chain with "<< subHolding->getName() << "and " << upperHolding->getName() << endl;
    else if (upperHolding)
    {
        if (upperHolding->upperHolding)
            cout << "Holding in complete chain with "<< upperHolding->getName() << "and " << upperHolding->upperHolding->getName() << endl;
        else
            cout << "Holding connected with the upperholding " << upperHolding->getName() << endl;
    }
    else
    {
        if (subHolding->subHolding)
            cout << "Holding in complete chain with "<< subHolding->getName() << "and " << subHolding->subHolding->getName() << endl;
        else
            cout << "Holding connected with the subHolding " << subHolding->getName() << endl;
    }
    cout << endl;
}


Holding::~Holding()
{
    delete subHolding;
    delete upperHolding;
}


//getters
int Holding::getCost() const
{
    return cost;
}


bool Holding::isTapped() const
{
    return tapped;
}


bool Holding::isRevealed() const
{
    return revealed;
}


int Holding::getHarvestValue() const
{
    return harvestValue;
}


Holding *Holding::getUpperHolding() const
{
    return upperHolding;
}


Holding *Holding::getSubHolding() const
{
    return subHolding;
}


//setters
void Holding::setTapped(bool tapped)
{
    Holding::tapped = tapped;
}


void Holding::setRevealed(bool revealed)
{
    Holding::revealed = revealed;
}


void Holding::setHarvestValue(int harvestValue)
{
    Holding::harvestValue = harvestValue;
}


void Holding::setUpperHolding(Holding *upperHolding)
{
    Holding::upperHolding = upperHolding;
}


void Holding::setSubHolding(Holding *subHolding)
{
    Holding::subHolding = subHolding;
}
