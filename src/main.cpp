#include <iostream>
#include "game.h"

int main() {
    Game g;
    std::cout << "Welcome to Yahtzee! Your score is " << g.getTotalScore() << std::endl;
    return 0;
}
