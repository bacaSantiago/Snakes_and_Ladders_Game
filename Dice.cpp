#include "Dice.h"

Dice::Dice()
{
	diceNumber = 0;
}

void Dice::roll()
{
	// Create a random_device to obtain a random seed for the random number generator
	random_device rd;

	// Create an mt19937 engine and seed it with the random seed obtained from random_device
    mt19937 gen(rd()); // Note that using that number is hackeable

	// Create a uniform_int_distribution to define the range of integers (1 to 6) and generate the number
    uniform_int_distribution<int> dis(1, 6);
    diceNumber = dis(gen);
}

int Dice::getDiceNumber(){
	return diceNumber;
}