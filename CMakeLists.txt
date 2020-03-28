cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project
        Deck.cpp
        Deck.hpp
        DeckBuilder.cpp
        DeckBuilder.hpp
        DynastyDeck.cpp
        DynastyDeck.hpp
        FateDeck.cpp
        FateDeck.hpp
        GameBoard.cpp
        GameBoard.hpp
        main.cpp
        Player.cpp
        Player.hpp
        Card.cpp Card.hpp GreenCard.cpp GreenCard.hpp BlackCard.cpp BlackCard.hpp Follower.cpp Follower.hpp Item.cpp Item.hpp Personality.cpp Personality.hpp Holding.cpp Holding.hpp Stronghold.cpp Stronghold.hpp initializeGameBoard.cpp initializeGameBoard.hpp Katana.cpp Katana.hpp Spear.cpp Spear.hpp Bow.cpp Bow.hpp Ninjato.cpp Ninjato.hpp Wakizashi.cpp Wakizashi.hpp Footsoldier.cpp Footsoldier.hpp Archer.cpp Archer.hpp Cavalry.cpp Cavalry.hpp Bushido.cpp Bushido.hpp Sieger.cpp Sieger.hpp Atakebune.cpp Atakebune.hpp Attacker.cpp Attacker.hpp Defender.cpp Defender.hpp Champion.cpp Champion.hpp Chancellor.cpp Chancellor.hpp Shogun.cpp Shogun.hpp Plain.cpp Plain.hpp Mine.cpp Mine.hpp GoldMine.cpp GoldMine.hpp CrystalMine.cpp CrystalMine.hpp Farmland.cpp Farmland.hpp GiftsandFavour.cpp GiftsandFavour.hpp Gameplay.cpp Gameplay.hpp)
