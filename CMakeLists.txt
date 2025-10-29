cmake_minimum_required(VERSION 3.14)
project(SE3540_Fall2025_A04_G09 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Main executable
add_executable(yahtzee
    src/main.cpp
    src/game.cpp
    src/dice.cpp
    src/scorecard.cpp
)
target_include_directories(yahtzee PRIVATE src)

# Catch2 for tests
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.3
)
FetchContent_MakeAvailable(catch2)

enable_testing()

# Test executable
add_executable(tests
    tests/test_game.cpp
    src/game.cpp
    src/dice.cpp
    src/scorecard.cpp
)
target_include_directories(tests PRIVATE src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)
