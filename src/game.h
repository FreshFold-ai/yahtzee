#pragma once
#include "dice.h"
#include "scorecard.h"
#include <array>
#include <algorithm>
#include <iostream>

class Game {
public:
    Game();
    void play();
    void roll5(std::array<int, 5> rerollIndices);
    void setFaceValues();
    int getCurrRound();
    int getTotalScore(int player) const;
    void pickSlot(int player, int slot, std::array<int, 5> values, std::array<int, 6> freqArray);
    const std::array<int, 5>& getFaceValues() const;
    const std::array<int, 5>& getSortedValues() const;
    const std::array<int, 6>& getFreqArray() const;
    const std::array<Dice, 5>& getGameDice() const;

private:
    int totalScore0 = 0;
    int currRound= 0;
    int totalScore1 = 0;
    static constexpr int maxRound = 13;
    std::array<int, 5> faceValues{};
    std::array<int, 5> sortedValues{};
    std::array<int, 6> freqArray{};
    std::array<Dice, 5> gameDice{};
    std::array<int, 5> rerollIndices{};
    Scorecard scorecard;
};
