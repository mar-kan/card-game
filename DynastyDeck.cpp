//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "DynastyDeck.hpp"
#include "Personality.hpp"


DynastyDeck::DynastyDeck()
{
    //default
    minCards = 40;
    maxCards = 60;
}


DynastyDeck::~DynastyDeck()
{
    list<BlackCard*>::iterator it;

    for (it = dynDeck.begin(); it != dynDeck.end(); it++)
    {
        dynDeck.remove((*it));
        //delete *it;
        it = dynDeck.begin();
    }
}


void DynastyDeck::pushCard(BlackCard* card)                     //pushes a blackCard in dynDeck list. facilitates pushing out of this class
{
    if (dynDeck.size() == maxCards)
        return;

    dynDeck.push_back(card);
}


BlackCard* DynastyDeck::popCard(BlackCard* card)                //pops a card from dynDeck list. facilitates popping out of this class
{
    dynDeck.remove(card);
    return card;
}


void DynastyDeck::revealDeck()                                  //reveals whole dynDeck
{
    list<BlackCard*>::iterator it;

    for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
        (*it)->setRevealed(true);
}


void DynastyDeck::PrintCards()                                  //prints all dynDeck's cards
{
    list <BlackCard*>::iterator it;

    for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
        (*it)->PrintCardStats();
}


BlackCard* DynastyDeck::findTarget(string prov)                 //finds a province of a player with name=prov and returns it, else returns null
{
    list<BlackCard*>::iterator it;

    for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
    {
        if (prov == (*it)->getName())
            return *it;
    }

    return nullptr;
}


BlackCard* DynastyDeck::searchDeck(string title)                //searches dynDeck for blackCard with name = title and returns it. if not found returns null
{
    list <BlackCard*>::iterator it;

    for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
    {
        if ((*it)->getName() == title)
            return *it;
    }
    return nullptr;
}


int DynastyDeck::calculateAttackPoints()
{
    Personality * pers;
    int ap=0;

    list <BlackCard*>::iterator it;
    for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
    {
        if ((*it)->isTapped())
            continue;

        pers = reinterpret_cast<Personality*>(*it);
        ap += pers->getAttack();
    }
    delete pers;
    return ap;
}


int DynastyDeck::calculateDefensePoints()
{
    Personality * pers;
    int dp=0;

    list <BlackCard*>::iterator it;

    for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
    {
        if (!(*it)->isTapped())
            continue;

        pers = reinterpret_cast<Personality*>(*it);
        dp += pers->getDefense();
    }
    delete pers;
    return dp;
}


void DynastyDeck::BattleConsequences(bool attacker, bool won, int ap, int dp)                 //changes armies of player according to battle state
{
    list <BlackCard*>::iterator it;
    Personality* pers = nullptr;
    Item* item = nullptr;

    if (won)
    {
        if (attacker)
        {
            for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
            {
                if ((*it)->isTapped())
                    continue;

                pers = reinterpret_cast<Personality*>(*it);
                if (pers->getAttack() >= ap - dp)
                {
                    popCard(*it);
                    delete *it;
                }
                else
                {
                    (*it)->setTapped(true);

                    if ((*it)->getType() == Card::PERSONALITY)
                    {
                        pers = reinterpret_cast<Personality*>(*it);
                        pers->PersonalityConsequences();
                    }
                    else
                    {
                        (*it)->setTapped(true);

                        if ((*it)->getType() == Card::PERSONALITY)
                        {
                            pers = reinterpret_cast<Personality*>(*it);
                            pers->PersonalityConsequences();
                        }
                        else
                        {
                            item = reinterpret_cast<Item*>(*it);
                            item->setDurability(item->getDurability() - 1);
                        }
                    }
                }
            }
        }
        else
        {
            for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
            {
                if ((*it)->isTapped())
                    continue;

                pers = reinterpret_cast<Personality*>(*it);
                if (pers->getAttack() >= ap - dp)
                {
                    popCard(*it);
                    delete *it;
                }
                else
                {
                    (*it)->setTapped(true);

                    if ((*it)->getType() == Card::PERSONALITY)
                    {
                        pers = reinterpret_cast<Personality*>(*it);
                        pers->PersonalityConsequences();
                    }
                    else
                    {
                        item = reinterpret_cast<Item*>(*it);
                        item->setDurability(item->getDurability() - 1);
                    }
                }
            }
        }
    }
    else
    {
        if (attacker)
        {
            for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
            {
                if ((*it)->isTapped())
                    continue;

                popCard(*it);
                delete *it;
            }
        }
        else
        {
            for (it=dynDeck.begin(); it!=dynDeck.end(); it++)
            {
                if (!(*it)->isTapped())
                    continue;

                popCard(*it);
                delete *it;
            }
        }
    }
    delete pers;
    delete item;
}


//getters
const list<BlackCard*> &DynastyDeck::getDynDeck() const
{
    return dynDeck;
}



