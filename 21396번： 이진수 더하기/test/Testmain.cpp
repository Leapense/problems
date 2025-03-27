#include "gtest/gtest.h"
#include "../cpp/src/main.h"

#include <vector>

class BinaryAdditionTest : public ::testing::Test
{
protected:
};

TEST_F(BinaryAdditionTest, Sample1)
{
    std::vector<unsigned int> v = {2, 2, 3, 3};
    unsigned int x = 0;
    EXPECT_EQ(countPairsWithXorSum(v, x), 2);
}

TEST_F(BinaryAdditionTest, Sample2)
{
    std::vector<unsigned int> v = {2, 3, 3, 2};
    unsigned int x = 1;
    EXPECT_EQ(countPairsWithXorSum(v, x), 4);
}

TEST_F(BinaryAdditionTest, Sample3)
{
    std::vector<unsigned int> v = {3, 7, 5, 6};
    unsigned int x = 4;
    EXPECT_EQ(countPairsWithXorSum(v, x), 1);
}

TEST_F(BinaryAdditionTest, AllSameXZero)
{
    std::vector<unsigned int> v = {5, 5, 5, 5, 5};
    unsigned int x = 0;
    EXPECT_EQ(countPairsWithXorSum(v, x), 10);
}

TEST_F(BinaryAdditionTest, NoMatchingPairs)
{
    std::vector<unsigned int> v = {1, 2, 4, 8, 16};
    unsigned int x = 100;
    EXPECT_EQ(countPairsWithXorSum(v, x), 0);
}

TEST_F(BinaryAdditionTest, SpecificPairs)
{
    std::vector<unsigned int> v = {1, 2, 3, 4, 5};
    unsigned int x = 7;
    EXPECT_EQ(countPairsWithXorSum(v, x), 2);
}

TEST_F(BinaryAdditionTest, LargeNumbers)
{
    unsigned int val1 = 1999999999;
    unsigned int val2 = 1000000001;
    unsigned int target_x = val1 ^ val2;
    std::vector<unsigned int> v = {val1, 5, val2, 10, val1, val2};

    EXPECT_EQ(countPairsWithXorSum(v, target_x), 4);
}

TEST_F(BinaryAdditionTest, EmptyVector)
{
    std::vector<unsigned int> v = {};
    unsigned int x = 10;
    EXPECT_EQ(countPairsWithXorSum(v, x), 0);
}

TEST_F(BinaryAdditionTest, SingleElementVector)
{
    std::vector<unsigned int> v = {123};
    unsigned int x = 0;
    EXPECT_EQ(countPairsWithXorSum(v, x), 0);
}

TEST_F(BinaryAdditionTest, MultipleOccurrences)
{
    std::vector<unsigned int> v = {1, 2, 1, 2, 1, 2};
    unsigned int x = 3;
    EXPECT_EQ(countPairsWithXorSum(v, x), 9);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}