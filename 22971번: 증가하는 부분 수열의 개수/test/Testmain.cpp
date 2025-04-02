#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>
using namespace std;

TEST(IncreasingSubsequenceTest, AllIncreasing) {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<long long> expected = {1, 2, 4, 8, 16};
    vector<long long> result = count_increasing_subsequences(A);
    EXPECT_EQ(result, expected);
}

TEST(IncreasingSubsequenceTest, AllEqual) {
    vector<int> A = {1, 1, 1, 1, 1};
    vector<long long> expected = {1, 1, 1, 1, 1};
    vector<long long> result = count_increasing_subsequences(A);
    EXPECT_EQ(result, expected);
}

TEST(IncreasingSubsequenceTest, MixedTest) {
    vector<int> A = {1, 2, 2, 4, 3};
    vector<long long> expected = {1, 2, 2, 6, 6};
    vector<long long> result = count_increasing_subsequences(A);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
