//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Farmland.hpp"


Farmland::Farmland(string n, int t, int spT) : Holding{n, t, spT, 3, 4}
{
    name = n;
    cost = 3;
    tapped = false;
    revealed = false;
    harvestValue = 4;

    upperHolding = nullptr;
    subHolding = nullptr;
}