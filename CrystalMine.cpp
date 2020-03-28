//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "CrystalMine.hpp"


CrystalMine::CrystalMine(string n, int t, int spT) : Holding{n, t, spT, 12, 6}
{
    name = n;
    cost = 12;
    tapped = false;
    revealed = false;
    harvestValue = 6;

    upperHolding = nullptr;
    subHolding = nullptr;
}