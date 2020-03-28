//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Chancellor.hpp"


Chancellor::Chancellor(string n, int t, int spT) : Personality{n, t, spT, 15, 5, 10, 8, 5, 4}
{
    name = n;
    cost = 15;
    tapped = false;

    revealed = false;

    attack = 5;
    defense = 10;
    honour = 8;
    dead = false;

    maxFollowers = 5;
    maxItems = 4;
}