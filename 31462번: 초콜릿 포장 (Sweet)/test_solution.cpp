// test_solution.cpp
#define UNIT_TEST
#include "gtest/gtest.h"
#include <vector>
#include <string>

// Declared in solution.cpp
bool isValid(const std::vector<std::string> &);

TEST(SweetChocolate, Sample1)
{
    std::vector<std::string> g = {"R", "RR"};
    EXPECT_TRUE(isValid(g));
}

TEST(SweetChocolate, Sample2)
{
    std::vector<std::string> g = {"R", "RR", "RBR", "RRRR"};
    EXPECT_FALSE(isValid(g));
}

// Additional edge cases
TEST(SweetChocolate, AllBlueN2)
{
    std::vector<std::string> g = {"B", "BB"};
    EXPECT_TRUE(isValid(g)); // one ▼‑blue piece
}

TEST(SweetChocolate, MixedValidN3)
{
    std::vector<std::string> g = {
        "R",
        "BB",
        "RRR"}; // 3 pieces: one ▲R on top, two ▼B below
    EXPECT_TRUE(isValid(g));
}

TEST(SweetChocolate, InvalidLeftEdgeBlue)
{
    std::vector<std::string> g = {"B", "BR"};
    EXPECT_FALSE(isValid(g)); // blue apex cannot be at column 0
}
