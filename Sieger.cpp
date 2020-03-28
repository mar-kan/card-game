//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Sieger.hpp"


Sieger::Sieger(string n, int t, int spT) : Follower{n, t, spT, 5, 3, 3, 2, 2, 3, "Green Card - Follower. Sieger card: " + n}
{
    name = n;
    cost = 5;
    tapped = false;

    attackBonus = 3;
    defenseBonus = 3;
    minimumHonor = 2;
    effectBonus = 2;
    effectCost = 3;
    cardText = "Green Card - Follower. Sieger card: " + name;
}