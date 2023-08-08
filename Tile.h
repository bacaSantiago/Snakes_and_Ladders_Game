#pragma once
#ifndef TILE_H
#define TILE_H

#include <iostream>
using namespace std;

class Tile
{
private:
    char type;

public:
    Tile();
    Tile(char _type);
    char getType();
    void setType(char _type);
};

#endif