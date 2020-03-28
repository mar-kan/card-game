#include "DeckBuilder.hpp"

using namespace std;

DeckBuilder::DeckBuilder()
{
	black = new list<BlackCard *>();
	green = new list<GreenCard *>();
	srand(unsigned(time(NULL)));
}

DeckBuilder::~DeckBuilder()
{
	list<BlackCard *>::iterator it;
	list<GreenCard *>::iterator it2;

	for (it = black->begin(); it != black->end(); it++)
	{
		black->remove((*it));
		delete *it;
		it = black->begin();
	}
	for (it2 = green->begin(); it2 != green->end(); it2++)
	{
		green->remove((*it2));
		delete *it2;
		it2 = green->begin();
	}
	delete black;
	delete green;
}


list<GreenCard *> *DeckBuilder::createFateDeck()
{
    //enum Type{PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};
    //added 2 ints in constructors
    //first int corresponds to Card::Type enum
    //second to Card::Followers, Items, Personalities or Holdings

	int i;
	for (i = 0; i < NO_FOOTSOLDIER; i++)
		green->push_back(new Footsoldier{"Peasants", 3, 1});
	for (i = 0; i < NO_ARCHER; i++)
		green->push_back(new Archer{"Elite Troops", 3, 2});
	for (i = 0; i < NO_SIEGER; i++)
		green->push_back(new Sieger{"Immortal Bushi", 3, 3});
	for (i = 0; i < NO_CAVALRY; i++)
		green->push_back(new Cavalry{"Unicorn Horses", 3, 4});
	for (i = 0; i < NO_NAVAL; i++)
		green->push_back(new Atakebune{"Yomi Ships", 3, 5});
	for (i = 0; i < NO_BUSHIDO; i++)
		green->push_back(new Bushido{"7 Samurai", 3, 6});

	for (i = 0; i < NO_KATANA; i++)
		green->push_back(new Katana{"Daijtso", 4, 1});
	for (i = 0; i < NO_BOW; i++)
		green->push_back(new Bow{"Yumi", 4, 3});
	for (i = 0; i < NO_SPEAR; i++)
		green->push_back(new Spear{"Kama", 4, 2});
	for (i = 0; i < NO_NINJATO; i++)
		green->push_back(new Ninjato{"Butterfly Dagger", 4, 4});
	for (i = 0; i < NO_WAKIZASHI; i++)
		green->push_back(new Wakizashi{"Kusanagi", 4, 5});

	return green;
}

list<BlackCard *> *DeckBuilder::createDynastyDeck()
{
	int i;
	//Create Personalities
	//NO_DEFENSIVE 10
	for (i = 0; i < NO_DEFENSIVE; i++)
		black->push_back(new Defender{"Footsoldiers", 1, 2});
	//NO_ATTACKING 10
	for (i = 0; i < NO_ATTACKING; i++)
		black->push_back(new Attacker{"Steadfast bushi", 1, 1});
	//NO_SHOGUN	2
	black->push_back(new Shogun{"Akodo Kaneka", 1, 3});
	black->push_back(new Shogun{"Isawa Shi en", 1, 3});
	//NO_CHANCELLOR 2
	black->push_back(new Chancellor{"Hida Shozen", 1, 4});
	black->push_back(new Chancellor{"Mirimuto Enishi", 1, 4});
	//NO_CHAMPION 1
	black->push_back(new Champion{"Hida Kisada", 1, 5});
	//Create holdings
	for (i = 0; i < NO_PLAIN; i++)
		black->push_back(new Plain{"Rice Fields", 2, 1});
	for (i = 0; i < NO_FARMS; i++)
		black->push_back(new Farmland{"Fish Farms", 2, 5});
	for (i = 0; i < NO_MINE; i++)
		black->push_back(new Mine{"Ashio Copper Mine", 2, 2});
	for (i = 0; i < NO_GOLD_MINE; i++)
		black->push_back(new GoldMine{"Konomai Gold Mine", 2, 3});
	for (i = 0; i < NO_CRYSTAL_MINE; i++)
		black->push_back(new CrystalMine{"Ichinokawa Crystal Mine", 2, 4});
	for (i = 0; i < NO_SOLO; i++)
		black->push_back(new GiftsandFavour{"Gifts and Favors", 2, 6});

	return black;
}

void DeckBuilder::deckShuffler(list<BlackCard *> *black)
{
	vector<BlackCard *> vect;
	list<BlackCard *>::iterator it;
	for (it = black->begin(); it != black->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	black->clear();

	vector<BlackCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		black->push_back((*it2));
}

void DeckBuilder::deckShuffler(list<GreenCard *> *green)
{
	vector<GreenCard *> vect;
	list<GreenCard *>::iterator it;
	for (it = green->begin(); it != green->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	green->clear();

	vector<GreenCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		green->push_back((*it2));
}