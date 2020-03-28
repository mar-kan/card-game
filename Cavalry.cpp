//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Cavalry.hpp"


Cavalry::Cavalry(string n, int t, int spT) : Follower{n, t, spT, 3, 4, 2, 3, 3, 4, "Green Card - Follower. Archer card: " + n}
{
    name = n;
    cost = 3;
    tapped = false;

    attackBonus = 4;
    defenseBonus = 2;
    minimumHonor = 3;
    effectBonus = 3;
    effectCost = 4;
    cardText = "Green Card - Follower. Archer card: " + name;
}