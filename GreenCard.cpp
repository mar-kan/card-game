//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include <iostream>
#include "GreenCard.hpp"
#include "Follower.hpp"
#include "Item.hpp"


GreenCard::GreenCard(string n, int t) : Card{n, t}
{
    name = n;
    type = Type(t);

    tapped = false;
}


int GreenCard::addBonus(int money, int honour)       //if bought adds bonuses and returns new amount of money of player, else returns same amount
{                                                    //casts to follower or item to have access to cards' data
    if (type == FOLLOWER)
    {
        Follower *temp = reinterpret_cast<Follower*>(this);

        if (money < temp->getEffectCost())
        {
            cout << "Not enough money"<<endl;
            return money;
        }
        if (honour < temp->getMinimumHonor())
        {
            cout << "Not honourable enough"<<endl;
            return money;
        }

        cout << "Do you want to upgrade your card "<< name <<"?" << endl;
        cout << "Cost: "<< temp->getEffectCost() <<endl << "Bonus: "<< temp->getEffectBonus()<<endl;
        cout <<"Enter y for yes, n for no"<< endl;
        string ans;
        cin >> ans;

        if (ans != "n")
            return money;

        //add bonuses to card stats
        temp->setAttackBonus(temp->getAttackBonus() + temp->getEffectCost());
        temp->setDefenseBonus(temp->getDefenseBonus() + temp->getEffectBonus());

        return money-temp->getEffectCost();
    }
    else
    {
        Item *temp = reinterpret_cast<Item*>(this);

        if (money < cost || honour < minimumHonor)
            return money;

        cout << "Do you want to upgrade your card "<< name <<"?" << endl;
        cout << "Cost: "<< temp->getEffectCost() <<endl << "Bonus: "<< temp->getEffectBonus()<<endl;
        cout <<"Enter y for yes, n for no"<< endl;
        string ans;
        cin >> ans;

        if (ans != "n")
            return money;

        //add bonuses to card stats
        temp->setAttackBonus(temp->getAttackBonus() + temp->getEffectCost());
        temp->setDefenseBonus(temp->getDefenseBonus() + temp->getEffectBonus());

        return money-temp->getEffectCost();
    }
}