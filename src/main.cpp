#include <iostream>
#include "game.h"

int main() {
    Game g;
    std::cout << "Welcome to Yahtzee! Your score is " << g.getTotalScore(3) << std::endl;
    return 0;
}
