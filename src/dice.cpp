#include <random>
#include "dice.h"

Dice::Dice()
{
}

int Dice::roll() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);
    return dist(gen);
}

int Dice::getFaceValue(){
	return this->faceValue;
}

void Dice::setFaceValue(int val){
	if(val>0 && val <7){
	    	this->faceValue = val;
	}
};

