//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "Stronghold.hpp"


Stronghold::Stronghold(string n, int t, int h, int m, int d) : BlackCard{n, t}
{
    name = n;
    honour = h;
    money = m;
    initialDefense = d;
}


Stronghold::~Stronghold()
{
    //nothing to delete manually
}


//getters
int Stronghold::getMoney() const
{
    return money;
}


int Stronghold::getHonour() const
{
    return honour;
}


int Stronghold::getInitialDefense() const
{
    return initialDefense;
}


//setters
void Stronghold::setMoney(int money)
{
    Stronghold::money = money;
}
