//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "Gameplay.hpp"


Gameplay::Gameplay(list<Player> player)
{
    players = player;
}


void Gameplay::ArrangeTurns()                                   //selection sorting in decreasing order players list by honour
{
    list <Player>::iterator max, i;

    for (it=players.begin(); it!=players.end(); it++)
    {
        max = it;
        for (i=it; i!=players.end(); i++)
        {
            if (i->getHonour() > max->getHonour())
                max = i;
        }
        swap(--it, max);
    }
}


void Gameplay::startingPhase()                                  //phase1:preparation of each players' cards and printing of his hand and provinces
{
    cout << "STARTING PHASE" << endl << endl;
    ArrangeTurns();

    for (it=players.begin(); it!=players.end(); it++)
    {
        cout << "Player " << it->getStronghold()->getName() << endl << endl;

        it->untapEverything();
        it->drawFateCard();
        it->revealProvinces();

        cout << "Hand: "<<endl;
        it->getHand().PrintCards();

        cout << "Provinces: "<<endl;
        it->getProvinces().PrintCards();

        cout << endl;
    }
}


void Gameplay::equipPhase()                                     //phase2: each player can equip green cards if he wants
{
    cout << "EQUIPMENT PHASE" << endl <<endl;
    this->ArrangeTurns();

    for (it=players.begin(); it!=players.end(); it++)
    {
        cout << "Player " << it->getStronghold()->getName() << endl << endl;

        if (it->getHand().isEmpty())
            cout << "Hand: empty"<<endl;
        else
        {
            cout << "Hand: "<<endl;
            it->getHand().PrintCards();
        }

        if (it->getArmy().getDynDeck().empty())
            cout << "Army: empty"<<endl;
        else
        {
            cout << "Army: "<<endl;
            it->getArmy().PrintCards();
        }
        cout <<endl;

        it->equipCards();
    }
}


void Gameplay::battlePhase()                                    //phase3: each player can attack another's province if he wants
{
    string strong, prov;
    char ans;

    cout << "BATTLE PHASE" << endl <<endl;
    this->ArrangeTurns();

    list <Player>::iterator it1;

    for (it=players.begin(); it!=players.end(); it++)
    {
        cout << "Player " << it->getStronghold()->getName() << endl << endl;

        //attack
        cout << "Do you want to attack?"<<endl<<"Enter y for yes, n for no"<<endl;
        cin.clear();
        cin >> ans;

        if (ans != 'y')
            continue;

        cout << "Prepare cards for attack"<<endl;
        it->prepareForBattle();

        cout <<"Enter name of player and province to attack to"<<endl;     //name of stronghold
        cin >> strong;
        cin >> prov;

        //find target player
        for (it1=players.begin(); it1!=players.end(); it1++)
        {
            if (it1->getStronghold()->getName() == strong)
                break;
        }

        if (it1 == players.end())
        {
            cout << "Invalid player"<<endl;
            return;
        }
        it->Attack(&*it1, prov);
    }
}


void Gameplay::economyPhase()                                   //phase4: each player can buy black cards if he wants
{
    cout << "ECONOMY PHASE" << endl <<endl;
    this->ArrangeTurns();

    for (it=players.begin(); it!=players.end(); it++)
    {
        cout << "Player " << it->getStronghold()->getName() << endl << endl;

        it->getProvinces().PrintCards();
        it->buyCards();
    }
}


void Gameplay::finalPhase()                                     //phase5: discarding extra hand cards and printing game stats
{
    cout << "FINAL PHASE" << endl <<endl;
    this->ArrangeTurns();

    for (it=players.begin(); it!=players.end(); it++)
    {
        cout <<"Players remaining: "<<endl;
        cout << "Player " << it->getStronghold()->getName() << endl;
        it->discardSurplusFateCards();
    }

    //print game stats
    cout << "Stats: "<<endl;
    int count=1;
    for (it=players.begin(); it!=players.end(); it++)
    {
        cout << "Player " << count << endl;
        it->PrintPlayerStats();
        cout << endl;

        count++;
    }
}


Player *Gameplay::checkWinningCondition()                       //if someone won returns a pointer to that player else returns null
{                                                               //prints if someone lost and removes him from the list
    for (it=players.begin(); it!=players.end(); it++)
    {
        if (!it->getNumberOfProvinces())
        {
            cout << "Player "<<it->getStronghold()->getName()<<"lost." << endl;

            players.remove(*it);
            cout << players.size() <<"players remaining." << endl;

            it=players.begin();
        }
    }
    if (players.size() == 1)
        return &*players.begin();

    return nullptr;
}


Gameplay::~Gameplay()
{
    players.clear();
}

