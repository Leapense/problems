#include <gtest/gtest.h>
#include <vector>
#include "../cpp/src/main.h"

using namespace std;

TEST(MaxContinuousBlocksTest, Sample1) {
    int N = 7;
    int K = 3;
    vector<int> L = {2, 3, 1, 5, 3, 5};
    int expected = 6;
    EXPECT_EQ(maxContinuousBlocks(N, K, L), expected);
}

TEST(MaxContinuousBlocksTest, Sample2) {
    int N = 7;
    int K = 3;
    vector<int> L = {2, 3, 1, 5, 3, 3};
    int expected = 7;
    EXPECT_EQ(maxContinuousBlocks(N, K, L), expected);
}

TEST(MaxContinuousBlocksTest, Sample3) {
    int N = 5;
    int K = 3;
    vector<int> L = {4, 4, 1, 1};
    int expected = 4;
    EXPECT_EQ(maxContinuousBlocks(N, K, L), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
