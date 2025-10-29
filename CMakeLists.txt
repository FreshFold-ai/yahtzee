cmake_minimum_required(VERSION 3.10)
project(Yahtzee VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files
add_executable(yahtzee
    src/main.cpp
    src/game.cpp
    src/dice.cpp
    src/scorecard.cpp
)
