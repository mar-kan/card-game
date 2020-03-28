//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#ifndef PROJECT_STRONGHOLD_HPP
#define PROJECT_STRONGHOLD_HPP


#include <string>
#include "BlackCard.hpp"
using namespace std;


class Stronghold: public BlackCard {

    string name;
    int honour;
    int money;
    int initialDefense;

public:
    Stronghold(string n, int t, int h, int m, int d);
    ~Stronghold() override;

    int getMoney() const;
    int getHonour() const override;
    int getInitialDefense() const;
    void setMoney(int money);
};


#endif //PROJECT_STRONGHOLD_HPP
