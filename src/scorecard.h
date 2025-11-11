#pragma once
#include "algorithm"
#include <iostream>
#include <array>

class Scorecard {
public: 
	Scorecard();
	void printScoreCard() const;
	void fillSlot(int slot, int player, std::array<int, 5> values);
	int calculatePoints(int slot, std::array<int, 5> values);
	void applyBonuses();

private:
	std::array<std::array<int, 13>, 2> scores = {};
	std::array<std::array<int, 13>, 2> slotFreq = {};
	int yahtzeeCount1 = 0;
	int yahtzeeCount2 = 0;
};
