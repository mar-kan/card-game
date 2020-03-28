//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include <time.h>
#include "GameBoard.hpp"
#include "initializeGameBoard.hpp"
#include "Gameplay.hpp"

using namespace std;


int main()
{
    srand(time(0));

    Personalities:
    enum{ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
    Holdings:
    enum{PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};
    Followers:
    enum{FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
    Items:
    enum{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};

    list<Player> players = initializeGameBoard();

    Gameplay play(players);

    Player * winner;
    while (!(winner = play.checkWinningCondition()))
    {
        play.startingPhase();
        play.equipPhase();
        play.battlePhase();
        play.economyPhase();
        play.finalPhase();
    }

    cout << "Player " << winner->getStronghold()->getName() <<" won"<<endl;
    delete winner;
    players.clear();

    cout << "Game over"<< endl;
    return 0;
}
