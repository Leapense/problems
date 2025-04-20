#include <gtest/gtest.h>
#include <sstream>
using namespace std;

long long solve(long long N, long long M, long long K)
{
    int totalRounds = __builtin_ctzll(N);
    int weakRounds = 63 - __builtin_clzll(K);
    return min<long long>(totalRounds, weakRounds + M);
}

TEST(PoppinSodaTest, Sample1)
{
    EXPECT_EQ(solve(8, 2, 4), 3);
}

TEST(PoppinSodaTest, Sample2)
{
    EXPECT_EQ(solve(16, 0, 6), 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}