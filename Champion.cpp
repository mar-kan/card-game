//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Champion.hpp"


Champion::Champion(string n, int t, int spT) : Personality{n, t, spT, 30, 20, 20, 12, 8, 6}
{
    name = n;
    cost = 30;
    tapped = false;

    revealed = false;

    attack = 20;
    defense = 20;
    honour = 12;
    dead = false;

    maxFollowers = 8;
    maxItems = 6;
}