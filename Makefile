game: main.o BlackCard.o Card.o Deck.o DeckBuilder.o DynastyDeck.o FateDeck.o Follower.o GameBoard.o GreenCard.o Holding.o Item.o Personality.o Player.o Stronghold.o initializeGameBoard.o Katana.o Spear.o Bow.o Ninjato.o Wakizashi.o Footsoldier.o Archer.o Cavalry.o Bushido.o Sieger.o Atakebune.o Attacker.o Defender.o Champion.o Chancellor.o Shogun.o Plain.o Mine.o GoldMine.o CrystalMine.o Farmland.o GiftsandFavour.o Gameplay.o
	
	g++ -g main.o BlackCard.o Card.o Deck.o DeckBuilder.o DynastyDeck.o FateDeck.o Follower.o GameBoard.o GreenCard.o Holding.o Item.o Personality.o Player.o Stronghold.o initializeGameBoard.o Katana.o Spear.o Bow.o Ninjato.o Wakizashi.o Footsoldier.o Archer.o Cavalry.o Bushido.o Sieger.o Atakebune.o Attacker.o Defender.o Champion.o Chancellor.o Shogun.o Plain.o Mine.o GoldMine.o CrystalMine.o Farmland.o GiftsandFavour.o Gameplay.o -o game

main.o: main.cpp
	g++ -g3 -c  main.cpp

BlackCard.o: BlackCard.cpp BlackCard.hpp
	g++ -g3 -c BlackCard.cpp

Card.o: Card.cpp Card.hpp
	g++ -g3 -c Card.cpp

Deck.o: Deck.cpp Deck.hpp
	g++ -g3 -c Deck.cpp

DeckBuilder.o: DeckBuilder.cpp DeckBuilder.hpp
	g++ -g3 -c DeckBuilder.cpp

DynastyDeck.o: DynastyDeck.cpp DynastyDeck.hpp
	g++ -g3 -c  DynastyDeck.cpp

FateDeck.o: FateDeck.cpp FateDeck.hpp
	g++ -g3 -c FateDeck.cpp

Follower.o: Follower.cpp Follower.hpp
	g++ -g3 -c Follower.cpp

GameBoard.o: GameBoard.cpp GameBoard.hpp
	g++ -g3 -c GameBoard.cpp

GreenCard.o: GreenCard.cpp GreenCard.hpp
	g++ -g3 -c GreenCard.cpp

Holding.o: Holding.cpp Holding.hpp
	g++ -g3 -c Holding.cpp

Item.o: Item.cpp Item.hpp
	g++ -g3 -c  Item.cpp

Personality.o: Personality.cpp Personality.hpp
	g++ -g3 -c Personality.cpp

Player.o: Player.cpp Player.hpp
	g++ -g3 -c Player.cpp

Stronghold.o: Stronghold.cpp Stronghold.hpp
	g++ -g3 -c Stronghold.cpp

initializeGameBoard.o: initializeGameBoard.cpp initializeGameBoard.hpp
	g++ -g3 -c initializeGameBoard.cpp

Katana.o: Katana.cpp Katana.hpp
	g++ -g3 -c Katana.cpp

Spear.o: Spear.cpp Spear.hpp
	g++ -g3 -c Spear.cpp

Bow.o: Bow.cpp Bow.hpp
	g++ -g3 -c Bow.cpp

Ninjato.o: Ninjato.cpp Ninjato.hpp
	g++ -g3 -c Ninjato.cpp

Wakizashi.o: Wakizashi.cpp Wakizashi.hpp
	g++ -g3 -c Wakizashi.cpp

Footsoldier.o: Footsoldier.cpp Footsoldier.hpp
	g++ -g3 -c  Footsoldier.cpp

Archer.o: Archer.cpp Archer.hpp
	g++ -g3 -c Archer.cpp

Cavalry.o: Cavalry.cpp Cavalry.hpp
	g++ -g3 -c Cavalry.cpp

Bushido.o: Bushido.cpp Bushido.hpp
	g++ -g3 -c Bushido.cpp

Sieger.o: Sieger.cpp Sieger.hpp
	g++ -g3 -c Sieger.cpp

Atakebune.o: Atakebune.cpp Atakebune.hpp
	g++ -g3 -c Atakebune.cpp

Attacker.o: Attacker.cpp Attacker.hpp
	g++ -g3 -c  Attacker.cpp

Defender.o: Defender.cpp Defender.hpp
	g++ -g3 -c Defender.cpp

Champion.o: Champion.cpp Champion.hpp
	g++ -g3 -c Champion.cpp

Chancellor.o: Chancellor.cpp Chancellor.hpp
	g++ -g3 -c Chancellor.cpp

Shogun.o: Shogun.cpp Shogun.hpp
	g++ -g3 -c Shogun.cpp

Plain.o: Plain.cpp Plain.hpp
	g++ -g3 -c Plain.cpp

Mine.o: Mine.cpp Mine.hpp
	g++ -g3 -c Mine.cpp

GoldMine.o: GoldMine.cpp GoldMine.hpp
	g++ -g3 -c GoldMine.cpp

CrystalMine.o: CrystalMine.cpp CrystalMine.hpp
	g++ -g3 -c CrystalMine.cpp

Farmland.o: Farmland.cpp Farmland.hpp
	g++ -g3 -c Farmland.cpp

GiftsandFavour.o: GiftsandFavour.cpp GiftsandFavour.hpp
	g++ -g3 -c GiftsandFavour.cpp

Gameplay.o: Gameplay.cpp Gameplay.cpp
	g++ -g3 -c Gameplay.cpp

clean:
	rm *.o game
