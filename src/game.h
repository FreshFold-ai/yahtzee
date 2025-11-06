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
    int getCurrScore();
    int getTotalScore(int player);
    void pickSlot(int player, int slot, std::array<int, 5> values);

private:
    int totalScore(0);
    int currRound(0);
    int maxRound(13) const;
    std::array<int, 5> faceValues;
    std::array<int, 5> sortedValues;
    std::arry<Dice, 5> gameDice;
    Scorecard scorecard;
};
