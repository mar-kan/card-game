//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Deck.hpp"
#include "Card.hpp"


Deck::Deck()
{
    //default
    minSize = 40;
    maxSize = 60;
}


Deck::~Deck() 
{
    list <Card*>::iterator it;

    for (it = deck.begin(); it != deck.end(); it++)
    {
        deck.remove((*it));
        //delete *it;
        it = deck.begin();
    }
}


void Deck::untapDeck()                              //untaps whole deck
{
    list <Card*>::iterator it;

    for (it=deck.begin(); it!=deck.end(); it++)
        (*it)->setTapped(false);
}


void Deck::tapDeck()                                //taps whole deck
{
    list <Card*>::iterator it;

    for (it=deck.begin(); it!=deck.end(); it++)
        (*it)->setTapped(true);
}


void Deck::PrintCards()                             //prints all decks' cards
{
    list <Card*>::iterator it;

    for (it=deck.begin(); it!=deck.end(); it++)
        (*it)->PrintCardStats();
}


Card* Deck::searchDeck(string title)                //searches deck for card with name = title and returns it. if not found returns null
{
    list <Card*>::iterator it;

    for (it=deck.begin(); it!=deck.end(); it++)
    {
        if ((*it)->getName() == title)
            return *it;
    }
    return nullptr;
}


void Deck::pushCard(Card* card)                     //pushes a card in deck list. facilitates pushing out of this class
{
    deck.push_back(card);
}


Card* Deck::popCard(Card* card)                     //pops a card from deck list. facilitates popping out of this class
{
    deck.remove(card);
    return card;
}


bool Deck::isEmpty()                                //checks if deck list is empty. facilitates checking out of this class
{
    return deck.empty();
}


void Deck::getCardFrom(Deck from)                   //pops a card from another deck and pushes it into this deck
{
    if (from.isEmpty())
        return;

    Card *card = from.popCard(*from.deck.begin());

    this->pushCard(card);

    card = nullptr;
    delete card;
}


//getters
list<Card*> Deck::getDeck() const
{
    return deck;
}
