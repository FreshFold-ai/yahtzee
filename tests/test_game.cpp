#include <catch2/catch_all.hpp>
#include "game.h"

TEST_CASE("New game starts with zero score", "[game]") {
    Game g;
    REQUIRE(g.getTotalScore() == 0);
}

TEST_CASE("Dice rolls produce values between 1 and 6", "[dice]") {
    Dice d;
    for (int i = 0; i < 100; ++i) {
        int val = d.roll();
        REQUIRE(val >= 1);
        REQUIRE(val <= 6);
    }
}
