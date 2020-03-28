//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Katana.hpp"


Katana::Katana(string n, int t, int spT) : Item{n, t, spT, 0, 2, 0, 1, 1, 2, 3, "Green Card - Item. Katana: " + n}
{
    name = n;
    cost = 0;
    tapped = false;

    attackBonus = 2;
    defenseBonus = 0;
    minimumHonor = 1;
    cardText = "Green Card - Item. Katana: " + name;

    effectBonus = 1;
    effectCost = 2;
    durability = 3;
}