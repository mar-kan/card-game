//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Ninjato.hpp"


Ninjato::Ninjato(string n, int t, int spT) : Item{n, t, spT, 4, 3, 3, 3, 2, 2, 4, "Green Card - Item. Katana: " + n}
{
    name = n;
    cost = 4;
    tapped = false;

    attackBonus = 3;
    defenseBonus = 3;
    minimumHonor = 3;
    cardText = "Green Card - Item. Katana: " + name;

    effectBonus = 2;
    effectCost = 2;
    durability = 4;
}