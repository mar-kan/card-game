//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Spear.hpp"


Spear::Spear(string n, int t, int spT) : Item{n, t, spT, 0, 0, 2, 1, 1, 2, 3, "Green Card - Item. Spear: " + n}
{
    name = n;
    cost = 0;
    tapped = false;

    attackBonus = 0;
    defenseBonus = 2;
    minimumHonor = 1;
    cardText = "Green Card - Item. Spear: " + name;

    effectBonus = 1;
    effectCost = 2;
    durability = 3;
}