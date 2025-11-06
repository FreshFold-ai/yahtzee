#include "scorecard.h"

Scorecard::Scorecard()
{
}

void Scorecard::printScoreCard() const{
	for(int i = 1; i < 3; i++){
		for(int j = 0; j < 13; j++){
			std::cout << scores[i][j] << endl;
		}
	}
}

void Scorecard::fillSlot(int slot, int player, std::array<int, 5> values){
	//if slot is unfilled then proceed to fill appropriately
	if(this.slotFreq[player][slot-1] == 0){
		this.scores[player][slot-1] = calculatePoints(slot, values)
		this.slotFreq[player][slot-1] += 1;
	} else {
		//ask for another input forever unless they input a valid slot (unfilled one)
		while(this.slotFreq[player][slot-1] != 0){
			std::cout << "That slot is already occupied, pick a different one:" << endl;
			std::cin >> slot;
		}
	}
}

int Scorecard::calculatePoints(int slot, std::array<int, 5> values){
	if(slot == 1){
		//calculate # of 1s, adding 1 per found int, returning the total points for 1s 
		int temp = 0
		for(int i = 0; i<5; i++){
			if(values[i] == 1){
				temp += 1;
			}
		}
		return temp;
	}
	if(slot == 2){
		//calculate # of 2s, adding 2 per found int, returning the total points for 2s 
		int temp = 0
		for(int i = 0; i<5; i++){
			if(values[i] == 2){
				temp += 2;
			}
		}
		return temp;
	}
	if(slot == 3){
		//calculate # of 3s, adding 3 per found int, returning the total points for 3s 
		int temp = 0
		for(int i = 0; i<5; i++){
			if(values[i] == 3){
				temp += 3;
			}
		}
		return temp;
	}
	if(slot == 4){
		//calculate # of 4s, adding 4 per found int, returning the total points for 4s 
		int temp = 0
		for(int i = 0; i<5; i++){
			if(values[i] == 4){
				temp += 4;
			}
		}
		return temp;
	}
	if(slot == 5){
		//calculate # of 5s, adding 5 per found int, returning the total points for 5s 
		int temp = 0
		for(int i = 0; i<5; i++){
			if(values[i] == 5){
				temp += 5;
			}
		}
		return temp;
	}
	if(slot == 6){
		//calculate # of 6s, adding 6 per found int, returning the total points for 6s 
		int temp = 0
		for(int i = 0; i<5; i++){
			if(values[i] == 6){
				temp += 6;
			}
		}
		return temp;
	}
	if(slot == 7){
		//check if 3 of kind
	}
	if(slot == 8){
		//check if 4 of kind
	}
	if(slot == 9){
		//check if full house
	}
	if(slot == 10){
		//check if small str8
	}
	if(slot == 11){
		//check if large str8
	}
	if(slot == 12){
		//calculate chance
	}
	if(slot == 13){
		//calculate yahtzee 
			//tricky, if already have a yahtzee, +100 and fills top level table
	}

}


void applyBonuses() const{

}


