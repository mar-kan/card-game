//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "FateDeck.hpp"

FateDeck::FateDeck()
{
    //default
    minCards = 40;
    maxCards = 60;
}


void FateDeck::pushCard(GreenCard* card)                     //pushes a greenCard in fateDeck list. facilitates pushing out of this class
{
    if (fateDeck.size() == maxCards)
        return;

    fateDeck.push_back(card);
}


FateDeck::~FateDeck()
{
    list<GreenCard*>::iterator itf;
    for (itf = fateDeck.begin(); itf != fateDeck.end(); itf++)
    {
        fateDeck.remove((*itf));
        //delete *itf;
        itf = fateDeck.begin();
    }
}