//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef FATEDECK_H
#define FATEDECK_H

#include "Deck.hpp"
#include "GreenCard.hpp"


class FateDeck: public Deck {                   //list of green cards that represents a fate deck

    list<GreenCard*> fateDeck;

    int minCards;
    int maxCards;

public:
    FateDeck();
    void pushCard(GreenCard*);
    ~FateDeck();
};


#endif
