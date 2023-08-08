#pragma once
#ifndef TILELADDER_H
#define TILELADDER_H

#include "Tile.h"
using namespace std;

class TileLadder : public Tile // Inheritance
{
private:
    int reward;

public:
    TileLadder();
    TileLadder(char _type, int _reward);
    int getReward();
};

#endif