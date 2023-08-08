#pragma once
#ifndef TILESNAKE_H
#define TILESNAKE_H

#include "Tile.h"
using namespace std;

class TileSnake : public Tile // Inheritance
{
private:
    int penalty;

public:
    TileSnake();
    TileSnake(char _type, int _penalty);
    int getPenalty();
};

#endif