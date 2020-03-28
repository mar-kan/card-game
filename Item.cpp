//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "Item.hpp"
#include "Katana.hpp"
#include "Spear.hpp"
#include "Bow.hpp"
#include "Ninjato.hpp"
#include "Wakizashi.hpp"


Item::Item(string n, int t, int spT, int c, int at, int def, int hon, int bon, int bc, int d, string txt) : GreenCard{n, t}
{
    name = n;
    typeI = Items(spT);
    tapped = false;

    cost = c;
    attackBonus = at;
    defenseBonus = def;
    minimumHonor = hon;
    cardText = txt;

    effectBonus = bon;
    effectCost = bc;

    durability = d;
}


int Item::getItemType()                 //returns int that corresponds to Items enum
{
    return Items(typeI);
}


void Item::PrintItem()                  //prints item's card stats
{
    cout << "Card: " << name << endl;
    cout << "Cost: " << cost << endl;

    cout << "Item Type: ";
    if (typeI == KATANA)
        cout << "Katana"<< endl;
    else if (typeI == SPEAR)
        cout << "Spear"<< endl;
    else if (typeI == BOW)
        cout << "Bow"<< endl;
    else if (typeI == NINJATO)
        cout << "Ninjato"<< endl;
    else if (typeI == WAKIZASHI)
        cout << "Wakizashi"<< endl;
    else return;

    if (tapped)
        cout << "Tapped: yes"<<endl;
    else
        cout <<"Tapped: no"<<endl;

    cout << "Attack: " << attackBonus << endl;
    cout << "Defense: " << defenseBonus << endl;
    cout << "Minimum Honor Required: " << minimumHonor << endl;

    cout << "Effect Bonus: " << effectBonus << endl;
    cout << "Effect Cost: " << effectCost << endl;

    cout << "Card text: " << cardText << endl;

    cout << "Durability: "<<durability<<endl;
    cout << endl;
}


//getters
int Item::getCost() const
{
    return cost;
}


bool Item::isTapped() const
{
    return tapped;
}


int Item::getAttackBonus() const
{
    return attackBonus;
}


int Item::getDefenseBonus() const
{
    return defenseBonus;
}


int Item::getMinimumHonor() const
{
    return minimumHonor;
}


int Item::getEffectBonus() const
{
    return effectBonus;
}


int Item::getEffectCost() const
{
    return effectCost;
}


const string &Item::getCardText() const
{
    return cardText;
}


int Item::getDurability() const
{
    return durability;
}


//setters
void Item::setAttackBonus(int attackBonus)
{
    Item::attackBonus = attackBonus;
}


void Item::setDefenseBonus(int defenseBonus)
{
    Item::defenseBonus = defenseBonus;
}


void Item::setDurability(int durability)
{
    Item::durability = durability;

    if (durability == 0)
        delete this;
}