#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
private:
    int playerId;
    int currentPosition;

public:
    // Constructors
    Player();
    Player(int id);

    // Methods
    void move(int diceValue);

    // Setters and Getters
    int getCurrentPosition();
    void setCurrentPosition(int _currentPosition);
    int getPlayerId();
    void setPlayerId(int _id);
};

#endif


