# collect .cpp files and build executable "yahtzee"
file(GLOB_RECURSE YAHTZEE_SRCS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(yahtzee ${YAHTZEE_SRCS})

target_include_directories(yahtzee PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(yahtzee PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)