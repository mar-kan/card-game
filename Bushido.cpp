//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Bushido.hpp"

Bushido::Bushido(string n, int t, int spT) : Follower{n, t, spT, 8, 8, 8, 6, 3, 8, "Green Card - Follower. Bushido card: " + n}
{
    name = n;
    cost = 8;
    tapped = false;

    attackBonus = 8;
    defenseBonus = 8;
    minimumHonor = 6;
    effectBonus = 3;
    effectCost = 8;
    cardText = "Green Card - Follower. Bushido card: " + name;
}