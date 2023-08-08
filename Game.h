#pragma once
#ifndef GAME_H
#define GAME_H

// Los include son composition. Los : public son herencia, entonceas el public board va en los A y M
#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include <iostream> 
using namespace std; 

class Game //: public Board  // en realidad no hereda esto
{
protected:
    Board board;
    Dice myDice;
    vector <Player*> players;
    int turnCount;
    int numPlayers;
    int maxTurns;

public:
    Game();
    Game(int _size, int _numSnakes, int _sPenalty, int _numLadders, int _lReward, int _numPlayers, int _maxTurns);
    void displayTurnInfo(int turn, int player, int initialPos, int diceValue, char tileType, int newPosition);
};

#endif
