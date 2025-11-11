#include "game.h"

Game::Game()  
{
	gameDice.fill(Dice());
    faceValues.fill(0);
    sortedValues.fill(0);
}

int Game::getTotalScore(int player) const {
	return this->totalScore;
}
int Game::getCurrScore() const{
	return this->currRound;
}

void Game::play(){
	this->currRound += 1;
}

//roll5 rolls each of the 5 die, 
//and then this.setFaceValues() updates FaceValues to match the most recent roll
//and simultaneously updates the sortedValues array. 
void Game::roll5(){
	for(Dice die: this->gameDice){
		die.roll();
	}
	this->setFaceValues();
}

void Game::setFaceValues(){
	int i = 0;
	for(Dice die: this->gameDice){
		this->faceValues[i] = die.getFaceValue();
	}
	std::array<int, 5> face_copy = this->faceValues;
    std::sort(face_copy.begin(), face_copy.end());
}





