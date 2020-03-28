//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Wakizashi.hpp"


Wakizashi::Wakizashi(string n, int t, int spT) : Item{n, t, spT, 8, 5, 5, 3, 3, 3, 8, "Green Card - Item. Wakizashi: " + n}
{
    name = n;
    cost = 8;
    tapped = false;

    attackBonus = 5;
    defenseBonus = 5;
    minimumHonor = 3;
    cardText = "Green Card - Item. Wakizashi: " + name;

    effectBonus = 3;
    effectCost = 3;
    durability = 8;
}