#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>

using namespace std;

TEST(MimiTest, SampleTest1)
{
    vector<Color> colors = {
        {255, 0, 0},
        {0, 255, 0},
        {0, 0, 255}};

    Color target = {64, 64, 64};
    int result = computeMinDifference(colors, target);
    EXPECT_EQ(result, 63);
}

TEST(MimiTest, SampleTest2)
{
    vector<Color> colors = {
        {255, 255, 255},
        {255, 130, 151}};

    Color target = {255, 255, 255};
    int result = computeMinDifference(colors, target);
    EXPECT_EQ(result, 115);
}

TEST(MimiTest, AllSameColors)
{
    vector<Color> colors = {
        {100, 100, 100},
        {100, 100, 100},
        {100, 100, 100},
        {100, 100, 100}};

    Color target = {100, 100, 100};

    int result = computeMinDifference(colors, target);
    EXPECT_EQ(result, 0);
}

TEST(MimiTest, TwoColorsEdge)
{
    vector<Color> colors = {
        {0, 0, 0},
        {255, 255, 255}};
    Color target = {128, 128, 128};
    int result = computeMinDifference(colors, target);
    EXPECT_EQ(result, 3);
}

TEST(MimiTest, MaximumMixCount)
{
    vector<Color> colors = {
        {0, 0, 0},
        {10, 10, 10},
        {20, 20, 20},
        {30, 30, 30},
        {40, 40, 40},
        {50, 50, 50},
        {60, 60, 60},
        {70, 70, 70}};

    Color target = {35, 35, 35};
    int result = computeMinDifference(colors, target);
    EXPECT_GE(result, 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}