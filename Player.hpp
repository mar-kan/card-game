//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Stronghold.hpp"
#include "FateDeck.hpp"
#include "DynastyDeck.hpp"
#include "Holding.hpp"
#include "Personality.hpp"


class Player {                  //represents player / dynast

    int honour;
    Stronghold * stronghold = nullptr;

    int maxCards;
    int minCards;
    int numberOfProvinces;
    int maxHand;

    FateDeck fateDeck;         //the green draw deck
    DynastyDeck dynDeck;       //the black draw deck

    DynastyDeck provinces;
    Deck hand;

    DynastyDeck holdings;
    DynastyDeck army;

    //vector with names for strongholds
    vector<string> names = {"Golden Plains Outpost", "High House of Light", "Closed Shell Castle", "Mountain's Anvil Castle", "Seven Strings Keep", "City of the Open Hand", "Shiro City", "Red Fort"};

public:
    bool operator==(const Player &p) const{ return p.stronghold->getName() == stronghold->getName(); }  //helps c++ find() to know how to search for player

    Player(int, int);
    Stronghold * GenerateRandomStronghold();
    void PrintPlayerStats();
    void untapEverything();
    void drawFateCard();
    void revealProvinces();
    void equipCards();
    void buyCards();
    void prepareForBattle();
    void Attack(Player *, string);
    void discardSurplusFateCards();
    ~Player();

    int getHonour() const;
    int getNumberOfProvinces() const;
    Deck &getHand();
    DynastyDeck &getProvinces();
    Stronghold *getStronghold() const;
    DynastyDeck &getArmy();
};


#endif
