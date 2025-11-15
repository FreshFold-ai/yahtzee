#include <random>
#include "dice.h"

Dice::Dice() : faceValue(0) {}

int Dice::rollDice() 
{
    static thread_local std::mt19937 gen(std::random_device{}());
    static thread_local std::uniform_int_distribution<int> dist(1, 6);
    int val = dist(gen);
    this->faceValue = val;   // store the rolled value in the object
    return val;
}

int Dice::getFaceValue()
{
	return this->faceValue;
}

void Dice::setFaceValue(int val)
{
	if(val > 0 && val < 7) {
	    	this->faceValue = val;
	}
};

