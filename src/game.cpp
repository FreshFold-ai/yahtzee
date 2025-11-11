#include "game.h"

Game::Game()  
{
	gameDice.fill(Dice());
    faceValues.fill(0);
    sortedValues.fill(0);
	freqArray.fill(0);
}
const std::array<int, 5>& Game::getFaceValues() const {
    return faceValues;
}

const std::array<int, 5>& Game::getSortedValues() const {
    return sortedValues;
}

const std::array<int, 6>& Game::getFreqArray() const {
    return freqArray;
}

const std::array<Dice, 5>& Game::getGameDice() const {
    return gameDice;
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
	for(auto &die : this->gameDice){
		die.roll();
	}
	this->setFaceValues();
}

void Game::setFaceValues(){
    this->freqArray.fill(0);
    for (size_t i = 0; i < this->gameDice.size(); ++i) {
        int val = this->gameDice[i].getFaceValue();
        this->faceValues[i] = val;
        if (val >= 1 && val <= 6) this->freqArray[val - 1] += 1;
    }

    this->sortedValues = this->faceValues;
    std::sort(this->sortedValues.begin(), this->sortedValues.end());
}





