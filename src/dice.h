#pragma once
#include <random>

class Dice
{
	public:
		Dice();
		int rollDice();
		int getFaceValue();
		void setFaceValue(int v); 
	private:
		int faceValue = 0;
};

