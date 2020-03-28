//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_GAMEPLAY_HPP
#define PROJECT_GAMEPLAY_HPP

#include "GameBoard.hpp"

class Gameplay {

    list <Player> players;
    list <Player>::iterator it;

public:
    Gameplay(list<Player>);
    void ArrangeTurns();
    void startingPhase();
    void equipPhase();
    void battlePhase();
    void economyPhase();
    void finalPhase();
    Player* checkWinningCondition();
    ~Gameplay();
};


#endif //PROJECT_GAMEPLAY_HPP
