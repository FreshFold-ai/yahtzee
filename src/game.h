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
    void roll5();
    void setFaceValues();
    int getCurrRound();
    int getCurrScore() const;
    int getTotalScore(int player) const;
    void pickSlot(int player, int slot, std::array<int, 5> values);

private:
    int totalScore = 0;
    int currRound = 0;
    static constexpr int maxRound = 13;
    std::array<int, 5> faceValues{};
    std::array<int, 5> sortedValues{};
    std::array<Dice, 5> gameDice{};
    Scorecard scorecard;
};
