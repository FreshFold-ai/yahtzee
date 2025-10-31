#pragma once
#include <random>

class Dice{
	public:
		Dice();
		int roll() const;
		int getFaceValue() const;
		void setFaceValue(int v) const; 
	private:
		int faceValue = 0;
};

