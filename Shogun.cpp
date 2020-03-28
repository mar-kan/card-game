//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Shogun.hpp"


Shogun::Shogun(string n, int t, int spT) : Personality{n, t, spT, 15, 10, 5, 8, 4, 3}
{
    name = n;
    cost = 15;
    tapped = false;

    revealed = false;

    attack = 10;
    defense = 5;
    honour = 8;
    dead = false;

    maxFollowers = 4;
    maxItems = 3;
}