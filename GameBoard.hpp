//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>
#include "Player.hpp"

class GameBoard {

    int numOfPlayers;
    list <Player> players;
    list <Player>:: iterator it;

    int minCards;
    int maxCards;

public:
    GameBoard(int, int, int, list<Player>);
    ~GameBoard();
    void printGameStatistics();

    const list <Player> &getPlayers() const;
};


#endif
