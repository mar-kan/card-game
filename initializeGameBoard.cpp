//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297

#include <iostream>
#include "initializeGameBoard.hpp"


list<Player> initializeGameBoard()                                           //initializes players and their number, min and max number of cards for each player(same)
{
    int playernum = rand()%7 + 2;                                            //random num from [2, 8]
    int min = 40;                                                            //default limits
    int max = 60;

    list<Player> myplayers;
    int i;

    for (i=0; i<playernum; i++)                                              //create playernum players
    {
        //passes limits for decks and creates them in player constructor
        Player play(min, max);
        myplayers.push_back(play);
    }

    GameBoard board(playernum, min, max, myplayers);                         //create board
    cout << "Starting game!"<<endl<<endl;
    board.printGameStatistics();                                             //print stats

    return myplayers;
}