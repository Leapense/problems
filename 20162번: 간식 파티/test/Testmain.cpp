#include <gtest/gtest.h>
#include "../cpp/src/main.h"
#include <vector>

using namespace std;

TEST(MaxSatisfactionTest, SampleTest1)
{
    vector<int> snacks = {4, 5, 1, 2, 3};
    EXPECT_EQ(maxSatisfaction(snacks), 9);
}

TEST(MaxSatisfactionTest, SampleTest2)
{
    vector<int> snacks = {3, 7, 3, 4, 8, 5, 10, 9, 3, 4};
    EXPECT_EQ(maxSatisfaction(snacks), 28);
}

TEST(MaxSatisfactionTest, StrictlyIncreasing)
{
    // 평점이 엄격하게 증가하는 경우 모두 먹을 수 있음
    vector<int> snacks = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxSatisfaction(snacks), 15);
}

TEST(MaxSatisfactionTest, AllSameRating)
{
    // 모든 간식의 평점이 동일하면, 한 번만 먹을 수 있음.
    vector<int> snacks = {5, 5, 5, 5, 5};
    EXPECT_EQ(maxSatisfaction(snacks), 5);
}

TEST(MaxSatisfactionTest, DecreasingSequence)
{
    // 평점이 내림차순인 경우, 한 번만 먹는 것이 최선임 (가장 높은 평점 선택)
    vector<int> snacks = {10, 9, 8, 7, 6};
    EXPECT_EQ(maxSatisfaction(snacks), 10);
}

TEST(MaxSatisfactionTest, MixedSequence)
{
    // 예: {2, 5, 3, 7, 4, 8} -> 2, 5, 7, 8 로 먹으면 22
    vector<int> snacks = {2, 5, 3, 7, 4, 8};
    EXPECT_EQ(maxSatisfaction(snacks), 22);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
