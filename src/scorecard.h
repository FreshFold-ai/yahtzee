#pragma once
#include "algorithm"
#include <iostream>
#include <array>

class Scorecard {
public: 
	Scorecard();
	void printScorecard() const;
	void pickSlot(int slot, int player);
	int calculatePoints(int slot, std::array<int, 5> values);
	void assignPoints(int slot, int player, int points);
	void removeSlot(int slot, int player);
	void applyBonuses() const;

private:
	std::array<std::array<int, 13>, 2> scores = {};
	std::array<std::array<int, 13>, 2> slotFreq = {};
	int yahtzeeCount1 = 0;
	int yahtzeeCount2 = 0;
};
