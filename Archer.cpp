//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Archer.hpp"

Archer::Archer(string n, int t, int spT): Follower{n, t, spT, 0, 0, 2, 1, 1, 2, "Green Card - Follower. Archer card: " + n}
{
    name = n;
    cost = 0;
    tapped = false;

    attackBonus = 0;
    defenseBonus = 2;
    minimumHonor = 1;
    effectBonus = 1;
    effectCost = 2;
    cardText = "Green Card - Follower. Archer card: " + name;
}