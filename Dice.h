#pragma once
#ifndef DICE_H
#define DICE_H

#include <random>
using namespace std;

class Dice
{
private:
	int diceNumber;
public:
	Dice();
	void roll();
	int getDiceNumber();
};

#endif