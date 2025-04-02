#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>

TEST(MaxEvenSubsequenceTest, SampleTest) {
    std::vector<int> S = {1, 2, 3, 4, 5, 6, 7, 8};
    int K = 2;
    EXPECT_EQ(getMaxEvenSubsequence(S, K), 3);
}

TEST(MaxEvenSubsequenceTest, AllEven) {
    std::vector<int> S = {2, 4, 6, 8, 10};
    int K = 1;
    EXPECT_EQ(getMaxEvenSubsequence(S, K), 5);
}

TEST(MaxEvenSubsequenceTest, AllOdd) {
    std::vector<int> S = {1, 3, 5, 7};
    int K = 2;

    EXPECT_EQ(getMaxEvenSubsequence(S, K), 0);
}

TEST(MaxEvenSubsequenceTest, MixedTest) {
    std::vector<int> S = {2, 1, 2, 1, 2, 1, 2};
    int K = 2;
    EXPECT_EQ(getMaxEvenSubsequence(S, K), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
