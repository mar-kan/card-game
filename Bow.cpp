//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Bow.hpp"

Bow::Bow(string n, int t, int spT) : Item{n, t, spT, 2, 2, 2, 2, 3, 4, 5, "Green Card - Item. Bow: " + n}
{
    name = n;
    cost = 2;
    tapped = false;

    attackBonus = 2;
    defenseBonus = 2;
    minimumHonor = 2;
    cardText = "Green Card - Item. Bow: " + name;

    effectBonus = 3;
    effectCost = 4;
    durability = 5;
}