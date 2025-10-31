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
    std::array<int, 5> getFaceValues();
    int getCurrRound();
    int getCurrScore();
    int getTotalScore();
    void getValidSlots();
    void pickSlot(int slot);

private:
    int totalScore(0);
    int currRound(0);
    int maxRound(13) const;
    std::array<int, 5> faceValues;
    std::arry<Dice, 5> gameDice;
    Scorecard scorecard;
};
