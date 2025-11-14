#include "scorecard.h"

Scorecard::Scorecard()
{
    scores.fill({});
    slotFreq.fill({});
}

void Scorecard::printScoreCard(int player) const{
    std::cout << "\n=== Player " << player + 1 << " Score Card ===" << std::endl;
    
    // Upper section
    std::cout << "\n--- UPPER SECTION ---" << std::endl;
    std::cout << "1. Ones:     " << (slotFreq[player][0] ? std::to_string(scores[player][0]) : "[ ]") << std::endl;
    std::cout << "2. Twos:     " << (slotFreq[player][1] ? std::to_string(scores[player][1]) : "[ ]") << std::endl;
    std::cout << "3. Threes:   " << (slotFreq[player][2] ? std::to_string(scores[player][2]) : "[ ]") << std::endl;
    std::cout << "4. Fours:    " << (slotFreq[player][3] ? std::to_string(scores[player][3]) : "[ ]") << std::endl;
    std::cout << "5. Fives:    " << (slotFreq[player][4] ? std::to_string(scores[player][4]) : "[ ]") << std::endl;
    std::cout << "6. Sixes:    " << (slotFreq[player][5] ? std::to_string(scores[player][5]) : "[ ]") << std::endl;
    
    int upperTotal = 0;
    for(int i = 0; i < 6; i++) upperTotal += scores[player][i];
    std::cout << "Upper Total: " << upperTotal << std::endl;
	std::cout << "\n--- LOWER SECTION ---" << std::endl;
    std::cout << "7. Three of a Kind:  " << (slotFreq[player][6] ? std::to_string(scores[player][6]) : "[ ]") << std::endl;
    std::cout << "8. Four of a Kind:   " << (slotFreq[player][7] ? std::to_string(scores[player][7]) : "[ ]") << std::endl;
    std::cout << "9. Full House:       " << (slotFreq[player][8] ? std::to_string(scores[player][8]) : "[ ]") << std::endl;
    std::cout << "10. Small Straight:  " << (slotFreq[player][9] ? std::to_string(scores[player][9]) : "[ ]") << std::endl;
    std::cout << "11. Large Straight:  " << (slotFreq[player][10] ? std::to_string(scores[player][10]) : "[ ]") << std::endl;
    std::cout << "12. Chance:          " << (slotFreq[player][11] ? std::to_string(scores[player][11]) : "[ ]") << std::endl;
    std::cout << "13. Yahtzee:         " << (slotFreq[player][12] ? std::to_string(scores[player][12]) : "[ ]") << std::endl;
    
    int lowerTotal = 0;
    for(int i = 6; i < 13; i++) lowerTotal += scores[player][i];
    std::cout << "Lower Total: " << lowerTotal << std::endl;
    std::cout << "Total: " << (upperTotal + lowerTotal) << "\n" << std::endl;
}

void Scorecard::fillSlot(int slot, int player, std::array<int, 5> values, std::array<int, 6> freqArray){
	//if slot is unfilled then proceed to fill appropriately

	if(slot == 13){
		if(player == 0 && yahtzeeCount1 > 0){
			//we need to ask the user to pick a slot in the top table (0-5), for that player, which
			// is yet unfilled
			int slot2;
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
			int slot2;
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

int Scorecard::calculateTotal(int player){
	int total = 0;
	for(int i = 0; i < 13; i++){
		total += scores[player][i];
	}
	return total;
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

void Scorecard::applyBonuses(){
	//if the upper section score is >= 63, add 35 points
	for(int player = 0; player < 2; player++){
		int upperScore = 0;
		for(int slot = 0; slot < 6; slot++){
			upperScore += scores[player][slot];
		}
		if(upperScore >= 63){
			scores[player][6] += 35; //add bonus to 3 of a kind slot
		}
	}
}

