#include "Player.h"

// Default constructor
Player::Player()
{
    playerId = 0;
    currentPosition = 0;
}

// Parametrized constructor
Player::Player(int _id)
{ 
    playerId = _id;
    currentPosition = 1;
}

void Player::move(int _diceValue)
{
    currentPosition += _diceValue;
}

int Player::getCurrentPosition()
{
    return currentPosition;
}

void Player::setCurrentPosition(int _currentPosition){
    currentPosition = _currentPosition;
}

int Player::getPlayerId()
{
    return playerId;
}

void Player::setPlayerId(int _id){
    playerId = _id;
}