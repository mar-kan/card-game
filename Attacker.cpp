//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Attacker.hpp"

Attacker::Attacker(string n, int t, int spT) : Personality{n, t, spT, 5, 3, 2, 2, 4, 3}
{
    name = n;
    cost = 5;
    tapped = false;

   revealed = false;

    attack = 3;
    defense = 2;
    honour = 2;
    dead = false;

    maxFollowers = 4;
    maxItems = 3;
}