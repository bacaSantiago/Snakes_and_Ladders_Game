// Headers that make the game function
#include "Game.h"

// Default constructor
Game::Game() // Not used, in order to force the user to use the parametrized constructor
{
    turnCount = 1;
    numPlayers = 2;
    maxTurns = 30;
}

// Parametrized constructor that receives the number of players and initializes a board inherited
Game::Game(int _size, int _numSnakes, int _sPenalty, int _numLadders, int _lReward, int _numPlayers, int _maxTurns) : board(_size, _numSnakes, _sPenalty, _numLadders, _lReward), myDice()
{
    turnCount = 1;
    numPlayers = _numPlayers;
    maxTurns = _maxTurns;

    // Set an identificator for every player
    for (int i = 0; i < numPlayers; i++){
        players.push_back(new Player(i+1));
    }
}

// Information of the turn 
void Game::displayTurnInfo(int turn, int player, int initialPos, int diceValue, char tileType, int newPosition)
{
    cout << turn << " " << player << " " << initialPos << " " << diceValue << " " << tileType << " " << newPosition << endl;
}  

