#pragma once
#include "dice.cpp"

class Game {
public:
    Game();
    int getTotalScore() const;
private:
    int totalScore;
};
