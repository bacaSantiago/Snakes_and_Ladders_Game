#include "TileSnake.h"

using namespace std;

// Default constructor
TileSnake::TileSnake()
{
    penalty = -3;
}

// Parametrized constructor
TileSnake::TileSnake(char _type, int _penalty) : Tile(_type) // Inheritance
{
    penalty = _penalty;
}

int TileSnake::getPenalty(){
    return penalty;
}