//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef DYNASTYDECK_H
#define DYNASTYDECK_H

#include "Deck.hpp"
#include "BlackCard.hpp"

class DynastyDeck: public Deck {            //represents a list of black cards

    list<BlackCard*> dynDeck;

    int minCards;
    int maxCards;

public:
    DynastyDeck();
    void pushCard(BlackCard*);
    BlackCard* popCard(BlackCard*);
    void revealDeck();
    void PrintCards();
    BlackCard * findTarget(string);
    BlackCard * searchDeck(string);
    int calculateAttackPoints();
    int calculateDefensePoints();
    void BattleConsequences(bool, bool, int, int);
    ~DynastyDeck();

    const list<BlackCard*> &getDynDeck() const;



};
#endif
