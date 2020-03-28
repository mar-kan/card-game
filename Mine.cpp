//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Mine.hpp"


Mine::Mine(string n, int t, int spT) : Holding{n, t, spT, 5, 3}
{
    name = n;
    cost = 5;
    tapped = false;
    revealed = false;
    harvestValue = 3;

    upperHolding = nullptr;
    subHolding = nullptr;
}