#pragma once
#include "algorithm"
#include <iostream>
#include <array>

class Scorecard {
public: 
	Scorecard();
	void printScoreCard(int player) const;
	void fillSlot(int slot, int player, std::array<int, 5> values, std::array<int, 6> freqArray);
	int calculatePoints(int slot, int player, std::array<int, 5> values, std::array<int, 6> freqArray);
	int calculateTotal(int player);
	void applyBonuses();
	int getDieSum(std::array<int, 5> values);

private:
	std::array<std::array<int, 13>, 2> scores = {};
	std::array<std::array<int, 13>, 2> slotFreq = {};
	int yahtzeeCount1 = 0;
	int yahtzeeCount2 = 0;
};
