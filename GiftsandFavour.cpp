//Kanellaki Maria Anna - 1115201400060
//Matanis Panagiotis - 1115201400297


#include "GiftsandFavour.hpp"


GiftsandFavour::GiftsandFavour(string n, int t, int spT) : Holding{n, t, spT, 2, 2}
{
    name = n;
    cost = 2;
    tapped = false;
    revealed = false;
    harvestValue = 2;
}