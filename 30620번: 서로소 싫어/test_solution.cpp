#include <gtest/gtest.h>
#include <numeric>
#include <cmath>

extern std::vector<long long> solveOps(long long x, long long y);

static long long applyOps(long long x, const std::vector<long long> &ops)
{
    for (size_t i = 1; i < ops.size(); ++i)
    {
        x += ops[i];
    }
    return x;
}

TEST(SolveOpsTest, NoOpWhenEqual)
{
    auto v = solveOps(5, 5);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 0);
}

TEST(SolveOpsTest, SingleOpCase)
{
    // gcd(6,9)=3>1 → 한 번에
    auto v = solveOps(6, 9);
    ASSERT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(applyOps(6, v), 9);
    EXPECT_GT(std::gcd(6LL, std::llabs(v[1])), 1);
}

TEST(SolveOpsTest, DoubleOpCase)
{
    // gcd(7,12)=1 → 두 단계
    auto v = solveOps(7, 12);
    ASSERT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 2);

    long long after1 = 7 + v[1];
    EXPECT_GT(std::gcd(7LL, std::llabs(v[1])), 1); // 첫 연산 유효성
    EXPECT_EQ(applyOps(7, v), 12);
    EXPECT_GT(std::gcd(after1, std::llabs(v[2])), 1); // 두번째 연산 유효성
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}