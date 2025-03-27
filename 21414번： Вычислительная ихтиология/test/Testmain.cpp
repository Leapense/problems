#include "gtest/gtest.h"
#include "../cpp/src/main.h"

#include <vector>

class IchthyologyTest : public ::testing::Test
{
protected:
};

TEST_F(IchthyologyTest, Sample1)
{
    std::vector<int> initial_populations = {996, 1, 994};
    EXPECT_EQ(solveIchthyology(initial_populations), 7);
}

TEST_F(IchthyologyTest, AllFastBreeding)
{
    std::vector<int> initial_populations = {1000, 1000, 1000};
    EXPECT_EQ(solveIchthyology(initial_populations), 1);
}

TEST_F(IchthyologyTest, OneVerySlow)
{
    std::vector<int> initial_populations = {1, 1000};
    EXPECT_EQ(solveIchthyology(initial_populations), 999);
}

TEST_F(IchthyologyTest, FarApartCloseTimes)
{
    std::vector<int> initial_populations = {998, 1, 1, 1, 998};
    EXPECT_EQ(solveIchthyology(initial_populations), 2);
}

TEST_F(IchthyologyTest, TravelTimeMatters)
{
    std::vector<int> initial_populations = {990, 995};
    EXPECT_EQ(solveIchthyology(initial_populations), 19);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}