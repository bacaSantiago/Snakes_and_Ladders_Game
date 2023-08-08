#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "TileLadder.h"
#include "TileSnake.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Board
{
private:
	int size;
    int numSnakes;
    int numLadders;
    int sPenalty;
    int lReward;
    vector <Tile*> tiles;
    default_random_engine rng;

public:

    // Constructors
    Board();
    Board(int _size, int _numSnakes, int _sPenalty, int _numLadders, int _lReward);
    //~Board();

    // Methods
    Tile* getTile(int tileNumber);

    // Setters and Getters
    int getSize();
    void setSize(int _size);
};

#endif