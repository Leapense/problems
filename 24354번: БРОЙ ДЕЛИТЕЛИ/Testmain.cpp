#include <iostream>
#include <vector>
#include <utility>
#include <gtest/gtest.h>

std::pair<int, int> numDiv(int n) {
    std::vector<int> divisors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j]++;
        }
    }

    int bestNumber = 1;
    int maxDivCount = divisors[1];

    for (int i = 2; i <= n; i++) {
        if (divisors[i] > maxDivCount) {
            bestNumber = i;
            maxDivCount = divisors[i];
        }
    }

    return {bestNumber, maxDivCount};
}

TEST(NumDivTest, SampleInput1) {
    auto result = numDiv(20);
    EXPECT_EQ(result.first, 12);
    EXPECT_EQ(result.second, 6);
}

TEST(NumDivTest, SampleInput2) {
    auto result = numDiv(30);
    EXPECT_EQ(result.first, 24);
    EXPECT_EQ(result.second, 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
