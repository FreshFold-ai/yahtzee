#include <iostream>
#include "game.h"

int main() {
    Game g;
    std::cout << "Welcome to Yahtzee! Your score is " << g.getTotalScore(3) << std::endl;
    g.roll5();
    std::cout << "face values after roll: " << std::endl;
    for(int val : g.getFaceValues()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "sorted values after roll: " << std::endl;
    for(int val : g.getSortedValues()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "frequency array after roll: " << std::endl;
    for(int freq : g.getFreqArray()) {
        std::cout << freq << " ";
    }
    return 0;
}
