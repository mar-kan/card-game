//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Atakebune.hpp"

Atakebune::Atakebune(string n, int t, int spT) : Follower{n, t, spT, 3, 2, 4, 3, 3, 4, "Green Card - Follower. Atakebune: "+ n}
{
    name = n;
    cost = 3;
    tapped = false;

    attackBonus = 2;
    defenseBonus = 4;
    minimumHonor = 3;
    effectBonus = 3;
    effectCost = 4;
    cardText = "Green Card - Follower. Atakebune: " + name;
}