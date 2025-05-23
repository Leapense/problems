#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>

TEST(OddGCDMatchingTest, SampleTest1)
{
    std::vector<int> A = {6, 8, 9, 12, 13};
    EXPECT_EQ(oddGCDMatching(A), 2);
}

TEST(OddGCDMatchingTest, SampleTest2)
{
    std::vector<int> A = {10, 10, 10};
    EXPECT_EQ(oddGCDMatching(A), 0);
}

TEST(OddGCDMatchingTest, SampleTest3)
{
    std::vector<int> A = {4, 3, 2, 4, 5, 6, 3};
    EXPECT_EQ(oddGCDMatching(A), 3);
}

TEST(OddGCDMatchingTest, AllOdds)
{
    std::vector<int> A = {1, 3, 5, 7};
    EXPECT_EQ(oddGCDMatching(A), 2);
}

TEST(OddGCDMatchingTest, EqualEvenOdd)
{
    std::vector<int> A = {2, 3, 4, 5};
    EXPECT_EQ(oddGCDMatching(A), 2);
}

TEST(OddGCDMatchingTest, SingleOdd)
{
    std::vector<int> A = {7};
    EXPECT_EQ(oddGCDMatching(A), 0);
}

TEST(OddGCDMatchingTest, MixedCase)
{
    std::vector<int> A = {2, 2, 3, 3, 4, 5, 7, 8, 10, 11};

    EXPECT_EQ(oddGCDMatching(A), 5);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}