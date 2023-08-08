#include "Tile.h"

// Default constructor
Tile::Tile()
{
    type = '\0';
}

// Parametrized constructor
Tile::Tile(char _type)
{
    type = _type;
}

char Tile::getType()
{
    return type;
}

void Tile::setType(char _type)
{
    type = _type;
}

