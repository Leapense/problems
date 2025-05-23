#include <gtest/gtest.h>
#include "../cpp/src/main.h"
#include <vector>
using namespace std;

TEST(LargestExoticNumberTest, SampleTest1)
{
    vector<vector<int>> matrix = {
        {3, 2, 1},
        {5, 2, 3},
        {4, 3, 4}};

    EXPECT_EQ(findLargestExoticNumber(matrix), 4);
}

TEST(LargestExoticNumberTest, SampleTest2)
{
    vector<vector<int>> matrix = {
        {3, 2, 1, 4},
        {4, 2, 1, 4},
        {5, 1, 2, 1},
        {3, 1, 5, 6}};
    EXPECT_EQ(findLargestExoticNumber(matrix), 5);
}

TEST(LargestExoticNumberTest, SampleTest3)
{
    vector<vector<int>> matrix = {
        {1, 2},
        {2, 4}};
    EXPECT_EQ(findLargestExoticNumber(matrix), -1);
}

TEST(LargestExoticNumberTest, AllSameValues)
{
    vector<vector<int>> matrix = {
        {5, 5},
        {5, 5}};

    EXPECT_EQ(findLargestExoticNumber(matrix), 5);
}

TEST(LargestExoticNumberTest, NoExoticPair)
{
    vector<vector<int>> matrix = {
        {1, 2},
        {3, 4}};
    EXPECT_EQ(findLargestExoticNumber(matrix), -1);
}

TEST(LargestExoticNumberTest, MixedValues)
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {3, 2, 1},
        {2, 3, 1}};

    EXPECT_EQ(findLargestExoticNumber(matrix), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}