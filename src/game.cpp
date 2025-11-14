#include "game.h"

Game::Game()  
{
	gameDice.fill(Dice());
    faceValues.fill(0);
    sortedValues.fill(0);
	freqArray.fill(0);
    rerollIndices.fill(0);
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
    if (player == 0) {
        return totalScore0;
    } else {
        return totalScore1;
    }
}

void Game::play(){
	this->currRound += 1;
    std::cout << "Starting Yahtzee Game, Round: " << this->currRound << std::endl;
    while(this->currRound <= maxRound){
        //game logic here
        for(int i = 0; i < 2; i++){
            //each player's turn
            std::cout << "Player " << i+1 << "'s turn: Round " << this->currRound << std::endl;
            for(int j = 0; j < 3; j++){
                //up to 3 rolls
                this->roll5(this->rerollIndices);
                this->setFaceValues();
                std::cout << "Current Roll: ";
                for(int val : this->getFaceValues()){
                    std::cout << val << " ";
                }
                std::cout << std::endl;
                if(j < 2){
                    //ask player which dice to reroll
                    std::cout << "Enter indices (0-4) of dice to reroll, separated by spaces (enter -1 to stop):" << std::endl;
                    this->rerollIndices.fill(0);
                    int index;
                    int count = 0;
                    while(true){
                        std::cin >> index;
                        if(index == -1){
                            break;
                        }
                        if(index >= 0 && index < 5){
                            this->rerollIndices[count] = index;
                            count++;
                        } else {
                            std::cout << "Invalid index, try again." << std::endl;
                        }
                    }
                }
            }
            //after rolling, ask player to pick a slot
            int slot;
            std::cout << "Enter slot number (1-13) to fill:" << std::endl;
            std::cin >> slot;
            this->pickSlot(i, slot, this->getFaceValues(), this->getFreqArray());
            std::cout << "Player " << i+1 << "'s total score: " << this->getTotalScore(i) << std::endl;
        }
    }
    std::cout << "Game Over!" << std::endl;
    std::cout << "Final Scores - Player 1: " << this->getTotalScore(0) << ", Player 2: " << this->getTotalScore(1) << std::endl;
    if(this->totalScore0 > this->totalScore1){
        std::cout << "Player 1 wins!" << std::endl;
    } else if(this->totalScore1 > this->totalScore0){
        std::cout << "Player 2 wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}

//roll5 rolls each of the 5 die, 
//and then this.setFaceValues() updates FaceValues to match the most recent roll
//and simultaneously updates the sortedValues array. 
void Game::roll5(std::array<int, 5> rerollIndices){
	for(int index : rerollIndices){
        if(index>0){
            this->gameDice[index].roll();
        }
    }
	this->setFaceValues();
}

void Game::pickSlot(int player, int slot, std::array<int, 5> values, std::array<int, 6> freqArray){
    this->scorecard.fillSlot(slot, player, values, freqArray);
    if(player == 0){
        this->totalScore0 = this->scorecard.calculateTotal(0);
    } else {
        this->totalScore1 = this->scorecard.calculateTotal(1);
    }
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





