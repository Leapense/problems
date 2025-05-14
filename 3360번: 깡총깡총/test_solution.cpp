#include <gtest/gtest.h>
#include "solution.cpp"

TEST(Sample, Given) {
    EXPECT_EQ(countWays(6), 7);
}

TEST(EdgeCases, SmallN) {
    EXPECT_EQ(countWays(1), 1);
    EXPECT_EQ(countWays(2), 2);
    EXPECT_EQ(countWays(3), 3);
}

TEST(EdgeCases, JustBelowLimit) {
    EXPECT_NO_THROW(countWays(1'000'000'000));
}

TEST(Random, QuickBrute) {
    auto brute = [](int n) {
        long long cnt = 0;
        for (int a = 0; a * 3 <= n; ++a) {
            for (int b = 0; a * 3 + b * 2 <= n; ++b) {
                ++cnt;
            }
        }

        return cnt % 1'000'000LL;
    };

    for (int n = 0; n <= 40; ++n) {
        ASSERT_EQ(countWays(n), brute(n));
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}