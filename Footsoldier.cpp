//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Footsoldier.hpp"


Footsoldier::Footsoldier(string n, int t, int spT) : Follower{n, t, spT, 0, 2, 0, 1, 1, 2, "Green Card - Follower. Footsoldier card: " + n}
{
    name = n;
    cost = 0;
    tapped = false;

    attackBonus = 2;
    defenseBonus = 0;
    minimumHonor = 1;
    effectBonus = 1;
    effectCost = 2;
    cardText = "Green Card - Follower. Footsoldier card: " + name;
}
