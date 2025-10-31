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

void Scorecard::pickSlot(int slot, int player){

}

int calculatePoints(int slot, std::array<int, 5> values){

}

void assignPoints(int slot, int player, int points){

}

//needs a frequency array to update and check against
void removeSlot(int slot, int player){

}

void applyBonuses() const{

}


