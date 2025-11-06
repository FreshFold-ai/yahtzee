#include "game.h"

Game::Game()  
{
	std::fill(gameDice, gameDice+5, 0);
	std::fill(faceValues, faceValues+5, 0);
	std::fill(sortedValues, sortedValues+5, 0);
}

int Game::getTotalScore() const {
	return this.totalScore;
}
int Game::getCurrScore() const{
	return this.currRound;
}

void Game::play(){
	this.currRound += 1;
}

//roll5 rolls each of the 5 die, 
//and then this.setFaceValues() updates FaceValues to match the most recent roll
//and simultaneously updates the sortedValues array. 
void Game::roll5(){
	for(Dice die: this.gameDice){
		die.roll();
	}
	this.setFaceValues();
}

void Game::setFaceValues(){
	int i = 0;
	for(Dice die: this.gameDice){
		this.faceValues[i] = die.getFaceValue();
	}
	std::array<int, 5> face_copy = this.faceValues;
	this.sortedValues = std::sort(face_copy.begin(), face_copy.end());
}





