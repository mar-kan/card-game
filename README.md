# card-game
simplified version of Legend of the Five Rings

(without graphics)

Makefile Instructions:

Compilation instructions: $ make compile

Execution instructions: $ make execute

To clean up generated files: $ make clean

Also contains CMake.


Number of players is chosen at the start of the program at random and is a number between [2,8].

Minimum and maximum cards (Acher, Bow, etc.) are a random number selected at the start of the program and is common for all players
 
Decks: One black and one green deck are created which contain all the cards of the game. They are shuffled and dealed to the players.

Cards: They are created by DeckBuilder. There are 2 kinds of cards Green and Black. Green cards can be Followers or Items and Black Cards can be Personalites or
Holdings.

The order of the players' turns is random.
 
Each turn of a player has 5 phases: starting phase (player's stats are printed), equipment phase (cards and army of the player are printed and player can equip 
green cards if he wants to), battle phase (player can attack any other player's province), economy phase (player can buy black cards if he wants to) and final 
phase (extra hand cards are discarded and game stats are printed). 

The game is executed until there is a winner, meaning only one player remaining alive.
