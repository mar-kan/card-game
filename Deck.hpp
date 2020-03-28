//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef DECK_H
#define DECK_H

#include <string>
#include "Card.hpp"
using namespace std;


class Deck {

    list <Card*> deck;

    int minSize;
    int maxSize;

public:
    Deck();
    void untapDeck();
    void tapDeck();
    virtual void revealDeck() {};
    void PrintCards();
    Card * searchDeck(string);
    void pushCard(Card*);
    Card * popCard(Card*);
    void getCardFrom(Deck);
    bool isEmpty();
    ~Deck();

    list<Card*> getDeck() const;
};


#endif
