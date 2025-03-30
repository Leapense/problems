#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
using ll = long long;

TEST(ChessTest, SampleTest1) {
    vector<ll> expected = {4, 1, 1, 5, 5};
    vector<ll> result = solveTestCase(5, 5, 1, 3);
    EXPECT_EQ(expected,result);
}

TEST(ChessTest, SampleTest2) {
    vector<ll> expected = {0};
    vector<ll> result = solveTestCase(3, 3, 2, 2);
    EXPECT_EQ(expected, result);
}

TEST(ChessTest, SampleTest3) {
    vector<ll> expected = {8, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<ll> result = solveTestCase(5, 5, 3, 3);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
