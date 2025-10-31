#include "game.h"

Game::Game()  
{
	std::fill(gameDice, gameDice+5, 0);
	std::fill(faceValues, faceValues+5, 0);
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

void Game::roll5(){
	for(Dice die: this.gameDice){
		die.roll();
	}
}

std::array<int, 5> Game::getFaceValues(){
	int i = 0;
	for(Dice die: this.gameDice){
		this.faceValues[i] = die.getFaceValue();
	}
	return this.faceValues;
}

