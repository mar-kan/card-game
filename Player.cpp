//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "Player.hpp"
#include "DeckBuilder.hpp"


Player::Player(int min, int max)
{
    stronghold = GenerateRandomStronghold();
    honour = stronghold->getHonour();

    minCards = min;
    maxCards = max;
    numberOfProvinces = 4;
    maxHand = 6;

    int count = 0;

    //creates general decks with all the cards and shuffles them
    DeckBuilder *build = new DeckBuilder();

    list<GreenCard*> *green = build->createFateDeck();
    list<GreenCard*>::iterator it = green->begin();
    build->deckShuffler(green);

    list<BlackCard*> *black = build->createDynastyDeck();
    list<BlackCard*>::iterator it1 = black->begin();
    build->deckShuffler(black);

    //creates fateDeck with num E[minCards, maxCards] cards from green
    for (it=green->begin(); it!=green->end(); it++)
    {
        if (count == maxCards)
            break;

        GreenCard *newCard = *it;
        fateDeck.pushCard(newCard);

        green->remove(*it);
        count++;

        newCard = nullptr;
        delete newCard;
        it=green->begin();
    }
    if (count < minCards)           //if deck too small creates a new green deck and adds more
    {
        green = build->createFateDeck();
        build->deckShuffler(green);

        for (it=green->begin(); it!=green->end(); it++)
        {
            if (count == maxCards)
                break;

            GreenCard *newCard = *it;
            fateDeck.pushCard(newCard);

            green->remove(*it);
            count++;

            delete newCard;
            it=green->begin();
        }
    }

    //creates dynDeck with num E[minCards, maxCards] cards from black
    for (it1=black->begin(); it1!=black->end(); it1++)
    {
        if (count == maxCards)
            break;

        BlackCard *newCard = *it1;
        dynDeck.pushCard(newCard);

        black->remove(*it1);
        count++;

        delete newCard;
        it1=black->begin();
    }

    if (count < minCards)           //if deck too small creates a new green deck and adds more
    {
        black = build->createDynastyDeck();
        build->deckShuffler(black);

        for (it1=black->begin(); it1!=black->end(); it1++)
        {
            if (count == maxCards)
                break;

            BlackCard *newCard = *it1;
            dynDeck.pushCard(newCard);

            black->remove(*it1);
            count++;

            delete newCard;
            it1=black->begin();
        }
    }

    //creates provinces with first 4 cards of black
    while (provinces.getDynDeck().size() < 5)//4 cards + list.end()
    {
        build->deckShuffler(black);
        if (black->empty())                                 //if it empties generate a new black deck and shuffle it
        {
            black = build->createDynastyDeck();
            build->deckShuffler(black);
            it1 = black->begin();
        }

        BlackCard *newCard = *it1;
        provinces.pushCard(newCard);

        black->remove(*it1);
        it1=black->begin();
    }

    //builds hand with first 3 cards of green deck
    int i;
    for (i=0; i<3; i++)                                     //players start with 3 cards in their hand
    {
        build->deckShuffler(green);
        if (green->empty())                                 //if it empties generate a new green deck and shuffle it
        {
            green = build->createFateDeck();
            build->deckShuffler(green);
            it = green->begin();
        }
        GreenCard *newCard = *it;
        hand.pushCard(newCard);

        green->remove(*it);
        it = green->begin();
    }

    delete build;
}


Stronghold * Player::GenerateRandomStronghold()             //generates a stronghold with unique name and random values between limits
{
    //gets a random name from vector and removes it to avoid doubles
    int random = rand()%(names.size()-1)+1;
    string name = names[random];
    names.erase(names.begin() + random-1);

    //random nums within limits for the rest of the values
    honour = rand()%4 + 10;                                 //get a random number from [10, 13]
    int money = rand()%5 + 8;                               //get a random number from [8, 12]
    int initialDefense = rand()%6 + 10;                     //get a random number from [10, 15]

    //create and return stronghold
    Stronghold * strong = new Stronghold(name, 0, honour, money, initialDefense);
    return strong;
}


void Player::PrintPlayerStats()                             //print player's data and decks
{
    cout << "Stronghold name: " << stronghold->getName() << endl;
    cout << "Honour: " << honour << endl;

    cout << "Provinces: " << numberOfProvinces << endl<<endl;
    provinces.PrintCards();
    cout << endl;

    if (hand.isEmpty())
        cout << "Hand Empty"<<endl;
    else
    {
        cout << "Hand Cards: " << endl;
        hand.PrintCards();
    }

    if (holdings.isEmpty())
        cout << "Holdings: 0"<<endl;
    else
    {
        cout <<"Holdings:" << endl;
        holdings.PrintCards();
    }

    if (army.isEmpty())
        cout << "No army" << endl;
    else
    {
        cout <<"Army:" << endl;
        army.PrintCards();
    }
    cout << endl;
}


void Player::untapEverything()                              //untap every deck of player
{
    fateDeck.untapDeck();
    provinces.untapDeck();
    hand.untapDeck();
    holdings.untapDeck();
    army.untapDeck();
}


void Player::drawFateCard()                                 //draw a card from fateDeck and add it to hand
{
    hand.getCardFrom(fateDeck);
}


void Player::revealProvinces()                              //reveal all provinces of player
{
    provinces.tapDeck();
    provinces.revealDeck();
}


void Player::equipCards()                                   //player can equip any green cards from his hand to his provinces and personalities if he wants to
{
    string equip, pers;
    char ans;

    if (hand.isEmpty())
    {
        cout << "Hand empty. Can't equip cards now" <<endl<<endl;
        return;
    }
    if (army.getDynDeck().empty())
    {
        cout << "No army. Can't equip cards now" <<endl<<endl;
        return;
    }

    cout << "Do you want to equip a card?"<<endl<<"Enter y for yes, n for no"<<endl;
    cin >> ans;

    while (ans == 'y' && !hand.isEmpty())
    {
        cout << "Enter name of card to equip and which personality will equip it" << endl;
        cin >> equip >> pers;

        GreenCard *bought = reinterpret_cast<GreenCard*>(hand.searchDeck(equip));
        BlackCard *location = reinterpret_cast<BlackCard*>(provinces.searchDeck(pers));

        if (!bought)
            cout << "Invalid hand card"<<endl;
        else if (!location)
            cout << "Invalid personality"<<endl;
        else if (location->getType() != Card::PERSONALITY)
            cout << "Invalid card, not a personality"<<endl;
        else if (stronghold->getMoney() < bought->getCost())
            cout << "Not enough money"<<endl;
        else if (location->isTapped())
            cout <<"Personality tapped"<<endl;
        else
        {
            stronghold->setMoney(stronghold->getMoney() - bought->getCost());           //pay
            stronghold->setMoney(bought->addBonus(stronghold->getMoney(), honour));     //add bonus if player wants

            reinterpret_cast<Personality*>(location)->PushGreenCard(bought);                   //add it to personality's followers or items
            cout << "Card successfully equiped"<<endl;
        }
        delete bought;
        delete location;

        cout << "Do you want to equip more cards?"<<endl<<"Enter y for yes, n for no"<<endl;
        cin >> ans;
    }
    cout<<endl;
}


void Player::buyCards()                                     //player can buy holdings or personalities from his provinces if he wants to
{
    string buy;
    char ans;

    cout << "Do you want to buy a card?"<<endl<<"Enter y for yes, n for no"<<endl;
    cin >> ans;

    //buys selected province if enough money and honour and replaces it with an unrevealed card from dynDeck
    while (ans == 'y')
    {
        cout << "Enter name of province to buy" << endl;
        cin >> buy;

        BlackCard *bought = provinces.searchDeck(buy);           //searches from province with name = buy
        if (bought)
        {
            if (!bought->isRevealed())
                cout <<"Invalid province"<<endl;
            else if (stronghold->getMoney() < bought->getCost())
                cout << "Not enough money" << endl;
            else if (honour < bought->getHonour())
                cout << "Not enough honour" << endl;
            else
            {
                stronghold->setMoney(bought->effectBonus(stronghold->getMoney(), honour));      //pay

                //add it to player's holdings or army
                if (bought->getType() == Card::HOLDING)
                {
                    holdings.pushCard(bought);
                    bought->ChainHoldings(holdings.getDeck(), reinterpret_cast<Holding *>(bought));    //check for chains
                }
                else
                    army.pushCard(bought);

                //replace it with new unrevealed province from dynDeck
                provinces.pushCard(dynDeck.popCard(*dynDeck.getDynDeck().begin()));
                cout << "Bought card " << bought->getName() << endl;
            }
        }
        else
            cout << "Invalid province"<<endl;

        delete bought;

        cout << "Do you want to buy more cards?"<<endl<<"Enter y for yes, n for no"<<endl;
        cin.clear();
        cin >> ans;
    }
    cout<<endl;
}


void Player::prepareForBattle()                                                 //activates any untapped personalities the player wants for attack
{
    char ans;

    list<BlackCard*> arm = army.getDynDeck();
    list<BlackCard*>::iterator it;

    for (it=arm.begin(); it!=arm.end(); it++)
    {
        if ((*it)->isTapped())                         //tapped means busy somewhere else
            continue;

        (*it)->PrintCardStats();
        cout << "Do you want to use this personality?"<<endl<<"y for yes, n for no"<<endl;
        cin >> ans;

        if (ans == 'y')
            (*it)->setTapped(true);             //every tapped personality will attack
    }
}


void Player::Attack(Player * target, string prov)
{
    list<BlackCard*>::iterator it;

    Personality * pers;
    Item * item;

    BlackCard *prTarget = target->provinces.findTarget(prov);
    if (!prTarget)
    {
        cout << "Invalid target province"<<endl;
        return;
    }

    int ap = army.calculateAttackPoints();
    int dp = target->army.calculateDefensePoints();        //without provinces initial defense

    if (prTarget->getType() == Card::PERSONALITY) //all followers and items associated with personalities are deleted by their constructor
    {
        pers = reinterpret_cast<Personality *>(prTarget);
        dp += pers->getDefense();
    }

    if (ap > dp)
    {
        cout << "Attack successful"<<endl;

        //destroy province of target
        target->provinces.popCard(prTarget);

        if (prTarget->getType() == Card::PERSONALITY)
            delete pers;
        else
            delete item;

        target->army.BattleConsequences(false, false, ap, dp);                   //destroy associated army of target
        this->army.BattleConsequences(true, true, ap, dp);                       //change attacking army

        delete prTarget;
        cout << "Province destroyed"<<endl;
    }
    else if (ap == dp)
    {
        //destroy all attacking and defending armies
        target->army.BattleConsequences(false, false, ap, dp);
        this->army.BattleConsequences(true, false, ap, dp);
        cout << "Draw"<<endl;
    }
    else
    {
        target->army.BattleConsequences(false, true, ap, dp);                   //change associated army of target
        this->army.BattleConsequences(true, false, ap, dp);                     //destroy attacking army
        cout << "Attack unsuccessful"<<endl;
    }
}


void Player::discardSurplusFateCards()                                         //discards cards from player's hand until it is within its limits
{
    int count = 0;

    while (hand.getDeck().size() > maxHand)
    {
        delete hand.popCard(*hand.getDeck().begin());
        count++;
    }

    if (count)
        cout << "Discarded "<<count<<" cards"<<endl;
    else
        cout << "Didn't discard any cards"<<endl;
}


Player::~Player()
{
    //delete stronghold;
}


//getters
int Player::getHonour() const
{
    return honour;
}


int Player::getNumberOfProvinces() const
{
    return numberOfProvinces;
}


Deck &Player::getHand()
{
    return hand;
}


DynastyDeck &Player::getProvinces()
{
    return provinces;
}


Stronghold *Player::getStronghold() const
{
    return stronghold;
}


DynastyDeck &Player::getArmy()
{
    return army;
}
