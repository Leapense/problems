#include <iostream>
#include <numeric>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

long long computePassword(int K, const vector<int>& A) {
    long long lcm_value = A[0];
    for (size_t i = 1; i < A.size(); i++) {
        lcm_value = std::lcm(lcm_value, static_cast<long long>(A[i]));
    }
    return lcm_value - K;
}

TEST(PasswordTest, SampleInput1) {
    int K = 4;
    vector<int> A = {9, 8, 7};
    EXPECT_EQ(computePassword(K, A), 500);
}

TEST(PasswordTest, SampleInput2) {
    int K = 3;
    vector<int> A = {4, 9, 5, 12, 15};
    EXPECT_EQ(computePassword(K, A), 177);
}

TEST(PasswordTest, AdditionalTest) {
    int K = 2;
    vector<int> A = {5, 7, 11};
    EXPECT_EQ(computePassword(K, A), 383);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
