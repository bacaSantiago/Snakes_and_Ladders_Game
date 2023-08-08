#include "TileLadder.h"

// Default constructor
TileLadder::TileLadder()
{
    reward = 3;
}

// Parametrized constructor
TileLadder::TileLadder(char _type, int _reward) : Tile(_type) // Inheritance
{
    reward = _reward;
}

int TileLadder::getReward(){
    return reward;
}
