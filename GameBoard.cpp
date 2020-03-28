//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include <utility>
#include "GameBoard.hpp"


GameBoard::GameBoard(int playernum, int min, int max, list<Player> myplayers)
{
    numOfPlayers = playernum;
    minCards = min;
    maxCards = max;
    players = myplayers;
}


void GameBoard::printGameStatistics()                                   //prints all players' stats
{
    cout << "Playing:" << endl << endl;

    int count=1;

    for (it=players.begin(); it!=players.end(); it++)
    {
        cout << "Player " << count << endl;
        it->PrintPlayerStats();
        cout << endl;

        count++;
    }
}


GameBoard::~GameBoard()
{
    players.clear();
}


//getters
const list<Player> &GameBoard::getPlayers() const
{
    return players;
}
