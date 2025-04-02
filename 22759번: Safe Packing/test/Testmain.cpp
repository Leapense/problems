#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(PackingTest, SampleTest1) {
    int W = 4, F = 10;
    unsigned long long S = 30;
    vector<unsigned long long> items = {7, 15, 30, 5};
    vector<unsigned long long> fib = generateFibonacci(S);
    int expected = 3;
    EXPECT_EQ(maxPackableItems(W, F, S, items, fib), expected);
}

TEST(PackingTest, SampleTest2) {
    int W = 11, F = 100;
    unsigned long long S = 5812167;
    vector<unsigned long long> items = {20, 40, 30, 15, 17, 5812167, 23, 43, 33, 13, 37};
    vector<unsigned long long> fib = generateFibonacci(S);
    int expected = 10;
    EXPECT_EQ(maxPackableItems(W, F, S, items, fib), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
