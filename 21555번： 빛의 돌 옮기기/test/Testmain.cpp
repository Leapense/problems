#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>
#include <cstdint>

class LightStoneTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(LightStoneTest, Sample1)
{
    int n = 3;
    int64_t k = 2;
    std::vector<int64_t> a = {1, 7, 3};
    std::vector<int64_t> b = {9, 3, 4};
    int64_t expected = 10;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

TEST_F(LightStoneTest, Sample2)
{
    int n = 4;
    int64_t k = 0;
    std::vector<int64_t> a = {10, 1, 10, 1};
    std::vector<int64_t> b = {1, 10, 1, 10};

    int64_t expected = 4;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

TEST_F(LightStoneTest, SingleSegment)
{
    int n = 1;
    int64_t k = 1000;
    std::vector<int64_t> a = {5};
    std::vector<int64_t> b = {8};
    int64_t expected = 5;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

TEST_F(LightStoneTest, AlwaysDragCheaper)
{
    int n = 5;
    int64_t k = 100;
    std::vector<int64_t> a = {1, 2, 3, 4, 5};
    std::vector<int64_t> b = {1000, 1000, 1000, 1000, 1000};
    int64_t expected = 15;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

TEST_F(LightStoneTest, AlwaysCarryCheaper)
{
    int n = 4;
    int64_t k = 50;
    std::vector<int64_t> a = {200, 200, 200, 200};
    std::vector<int64_t> b = {10, 20, 5, 15};
    int64_t expected = 50;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

TEST_F(LightStoneTest, HighSwitchCost)
{
    int n = 3;
    int64_t k = 10000;
    std::vector<int64_t> a = {1, 100, 1};
    std::vector<int64_t> b = {10, 1, 10};
    int64_t expected = 21;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

TEST_F(LightStoneTest, SwitchIsBeneficial)
{
    int n = 4;
    int64_t k = 5;
    std::vector<int64_t> a = {1, 100, 100, 1};
    std::vector<int64_t> b = {100, 1, 1, 100};
    int64_t expected = 14;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

TEST_F(LightStoneTest, LargeCosts)
{
    int n = 2;
    int64_t k = 1'000'000'000;
    std::vector<int64_t> a = {1'000'000'000, 1'000'000'000};
    std::vector<int64_t> b = {1'000'000'000, 1'000'000'000};
    int64_t expected = 2'000'000'000;
    ASSERT_EQ(solve(n, k, a, b), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}