#include "scorecard.h"

Scorecard::Scorecard()
{
    scores.fill({});
    slotFreq.fill({});
}

void Scorecard::printScoreCard() const{
	for(int i = 1; i < 3; i++){
		for(int j = 0; j < 13; j++){
			std::cout << "Player " << i << ": ";
			std::cout << "Slot " << j << ": " << scores[i][j] << std::endl;
		}
	}
}

void Scorecard::fillSlot(int slot, int player, std::array<int, 5> values, std::array<int, 6> freqArray){
	//if slot is unfilled then proceed to fill appropriately

	if(slot == 13){
		if(player == 0 && yahtzeeCount1 > 0){
			//we need to ask the user to pick a slot in the top table (0-5), for that player, which
			// is yet unfilled
			std::cout << "You have already scored a Yahtzee! Pick a different slot in the upper section (1-6):" << std::endl;
			std::cin >> slot2;
			while(this->slotFreq[player][slot2-1] != 0){
				std::cout << "This is already full! Pick a different slot in the upper section (1-6):" << std::endl;
				std::cin >> slot;
			}
			this->scores[player][slot-1] = calculatePoints(slot, player, values, freqArray);
			this->scores[player][slot2-1] = calculatePoints(slot2, player, values, freqArray);
			this->slotFreq[player][slot-1] += 1;
			this->slotFreq[player][slot2-1] += 1;
			return;
		} else if(player == 1 && yahtzeeCount2 > 0){
			std::cout << "You have already scored a Yahtzee! Pick a different slot in the upper section (1-6):" << std::endl;
			std::cin >> slot2;
			while(this->slotFreq[player][slot2-1] != 0){
				std::cout << "This is already full! Pick a different slot in the upper section (1-6):" << std::endl;
				std::cin >> slot;
			}
			this->scores[player][slot-1] = calculatePoints(slot, player, values, freqArray);
			this->scores[player][slot2-1] = calculatePoints(slot2, player, values, freqArray);
			this->slotFreq[player][slot-1] += 1;
			this->slotFreq[player][slot2-1] += 1;
			return;
		}
	}

	if(this->slotFreq[player][slot-1] == 0){
		this->scores[player][slot-1] = calculatePoints(slot, player, values, freqArray);
		this->slotFreq[player][slot-1] += 1;
	} else {
		//ask for another input forever unless they input a valid slot (unfilled one)
		while(this->slotFreq[player][slot-1] != 0){
			std::cout << "That slot is already occupied, pick a different one:" << std::endl;
			std::cin >> slot;
		}
		this->scores[player][slot-1] = calculatePoints(slot, player, values, freqArray);
		this->slotFreq[player][slot-1] += 1;
	}
}

int Scorecard::calculatePoints(int slot, int player, std::array<int, 5> values, std::array<int, 6> freqArray){
	if(slot == 1){
		//calculate # of 1s, adding 1 per found int, returning the total points for 1s 
		int temp = 0;
		for(int i = 0; i<5; i++){
			if(values[i] == 1){
				temp += 1;
			}
		}
		return temp;
	}
	if(slot == 2){
		//calculate # of 2s, adding 2 per found int, returning the total points for 2s 
		int temp = 0;
		for(int i = 0; i < 5; i++){
			if(values[i] == 2){
				temp += 2;
			}
		}
		return temp;
	}
	if(slot == 3){
		//calculate # of 3s, adding 3 per found int, returning the total points for 3s 
		int temp = 0;
		for(int i = 0; i < 5; i++){
			if(values[i] == 3){
				temp += 3;
			}
		}
		return temp;
	}
	if(slot == 4){
		//calculate # of 4s, adding 4 per found int, returning the total points for 4s 
		int temp = 0;
		for(int i = 0; i<5; i++){
			if(values[i] == 4){
				temp += 4;
			}
		}
		return temp;
	}
	if(slot == 5){
		//calculate # of 5s, adding 5 per found int, returning the total points for 5s 
		int temp = 0;
		for(int i = 0; i<5; i++){
			if(values[i] == 5){
				temp += 5;
			}
		}
		return temp;
	}
	if(slot == 6){
		//calculate # of 6s, adding 6 per found int, returning the total points for 6s 
		int temp = 0;
		for(int i = 0; i<5; i++){
			if(values[i] == 6){
				temp += 6;
			}
		}
		return temp;
	}
	if(slot == 7){
		//check if 3 of kind
		int temp = 0;
		for(int i = 0; i<6; i++){
			if(freqArray[i] == 3){
				temp += getDieSum(values);
			}
		}
		return temp;
	}

	if(slot == 8){
		//check if 4 of kind
		int temp = 0;
		for(int i = 0; i<6; i++){
			if(freqArray[i] == 4){
				temp += getDieSum(values);
			}
		}
		return temp;
	}

	if(slot == 9){
		//check if full house
		int temp = 0;
		for(int i = 0; i<6; i++){
			if(freqArray[i] == 3){
				for(int j = 0; j<6; j++){
					if(freqArray[j] == 2){
						temp += 25;
					}
				}
			}
		}
		return temp;
	}

	if(slot == 10){
		//check if small str8
		int temp = 0;
		for(int i = 0; i<6; i++){
			if(freqArray[i] >= 1){
				temp += 1;
			} else {
				temp = 0;
			}
			if(temp >= 4){
				return 30;
			}
		}
	}
	
	if(slot == 11){
		//check if large str8
		int temp = 0;
		for(int i = 0; i<6; i++){
			if(freqArray[i] >= 1){
				temp += 1;
			} else {
				temp = 0;
			}
			if(temp >= 5){
				return 40;
			}
		}
	}

	if(slot == 12){
		//calculate chance
		return getDieSum(values);
	}

	if(slot == 13){
		//calculate yahtzee 
		for(int i = 0; i<6; i++){
			if(freqArray[i] == 5){
				if(player == 0){
					if(yahtzeeCount1 > 0){
						//already have a yahtzee, add 100 points to yahtzee count
						yahtzeeCount1 += 1;
						return 100;
					}
					yahtzeeCount1 += 1;
					return 50;
				} else {
					if(yahtzeeCount2 > 0){
						//already have a yahtzee, add 100 points to yahtzee count
						yahtzeeCount2 += 1;
						return 100;
					}
					yahtzeeCount2 += 1;
					return 50;
				}
			}
		}
		return 0;
	}

	return 0;
}

int Scorecard::getDieSum(std::array<int, 5> values){
	int sum = 0;
	for(int i = 0; i<5; i++){
		sum += values[i];
	}
	return sum;
}

int Scorecard::calculateTotal(int player){
	int total = 0;
	for(int i = 0; i < 13; i++){
		total += scores[player][i];
	}
	return total;
}

void Scorecard::applyBonuses(){

}

