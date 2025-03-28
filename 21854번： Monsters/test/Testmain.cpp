#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>

class MonstersTest : public ::testing::Test
{
protected:
};

TEST_F(MonstersTest, SampleCase)
{
    std::vector<int64_t> k_values = {3, 7};
    EXPECT_EQ(calculate_total_sum(k_values), 136LL);
}

TEST_F(MonstersTest, SingleMonster)
{
    std::vector<int64_t> k_values = {10};
    EXPECT_EQ(calculate_total_sum(k_values), 1024LL);
}

TEST_F(MonstersTest, ZeroFingers)
{
    std::vector<int64_t> k_values = {0};
    EXPECT_EQ(calculate_total_sum(k_values), 1LL);
}

TEST_F(MonstersTest, MultipleZeroFingers)
{
    std::vector<int64_t> k_values = {0, 0, 0, 0};
    EXPECT_EQ(calculate_total_sum(k_values), 4LL);
}

TEST_F(MonstersTest, MixedFingers)
{
    std::vector<int64_t> k_values = {1, 2, 3, 4, 5};
    EXPECT_EQ(calculate_total_sum(k_values), 62LL);
}

TEST_F(MonstersTest, LargeK)
{
    std::vector<int64_t> k_values = {30};
    EXPECT_EQ(calculate_total_sum(k_values), 73741817LL);
}

TEST_F(MonstersTest, MultipleLargeK)
{
    std::vector<int64_t> k_values = {30, 30};
    EXPECT_EQ(calculate_total_sum(k_values), 147483634LL);
}

TEST_F(MonstersTest, MaxK)
{
    std::vector<int64_t> k_values = {1000000000};
    EXPECT_EQ(calculate_total_sum(k_values), 860376611LL);
}

TEST_F(MonstersTest, MultipleMaxK)
{
    std::vector<int64_t> k_values = {1000000000, 1000000000};
    EXPECT_EQ(calculate_total_sum(k_values), 720753215LL);
}

TEST_F(MonstersTest, EmptyInput)
{
    std::vector<int64_t> k_values = {};
    EXPECT_EQ(calculate_total_sum(k_values), 0LL);
}

TEST_F(MonstersTest, MixedZeroAndNonZero)
{
    std::vector<int64_t> k_values = {0, 5, 0, 10};
    EXPECT_EQ(calculate_total_sum(k_values), 1058LL);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}