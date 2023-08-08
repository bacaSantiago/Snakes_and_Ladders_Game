#include "Board.h"

// Default constructor
Board::Board()  // Not used, in order to force the user to use the parametrized constructor
{
    size = 30;
    numSnakes = 3;
    sPenalty = -3;
    numLadders = 3;
    lReward = 3;
}

// Parametrized constructor
Board::Board(int _size, int _numSnakes, int _sPenalty, int _numLadders, int _lReward)
{
    size = _size;
    numSnakes = _numSnakes;
    sPenalty = _sPenalty;
    numLadders = _numLadders;
    lReward = _lReward;

    tiles.resize(size, new Tile('N'));  // Initialize all tiles as normal ('N')

    // Create a random_device to obtain a random seed for the random number generator
    random_device rd;

    // Create a seed with the random seed obtained from random_device
    rng = default_random_engine(rd());

    // Generate random positions for snakes ('S')
    uniform_int_distribution<int> snakeDistribution(1, size-1); // -1 so that no snake is generated at the final tile
    for (int i = 0; i < numSnakes; i++) {
        int snakePos = snakeDistribution(rng);
        if (tiles[snakePos - 1] -> getType() == 'N') {
            tiles[snakePos -1] = new TileSnake('S', sPenalty); // Polymorphism
        } 
        else {
            i--;  // Try again if the position is already occupied by a snake
        }
    }

    // Generate random positions for ladders ('L')
    uniform_int_distribution<int> ladderDistribution(1, size-1); // -1 so that no ladder is generated at the final tile
    for (int i = 0; i < numLadders; i++) {
        int ladderPos = ladderDistribution(rng);
        if (tiles[ladderPos - 1] -> getType() == 'N') {
            tiles[ladderPos -1] = new TileLadder('L', lReward); // Polymorphism
        } 
        else {
            i--;  // Try again if the position is already occupied by a snake or ladder
        }
    }
}

/*
Board::~Board()
{
    // Deallocate the dynamically allocated tiles
    for (int i = 0; i < tiles.size(); i++) {
        delete tiles[i];
    }
}*/

Tile* Board::getTile(int tileNumber){
    return tiles[tileNumber - 1];
}

int Board::getSize(){
    return size;
}

void Board::setSize(int _size){
    size = _size;
}