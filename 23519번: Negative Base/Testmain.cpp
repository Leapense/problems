#include <iostream>
using namespace std;

long long solve(int k) {
    if (k == 1) return 0;
    else return (k % 2 == 0) ? (1LL << k) : -(1LL << k);
}

#ifndef UNIT_TESTS

int main()
{
    int k;
    cin >> k;
    cout << solve(k) << "\n";
    return 0;
}

#endif

#ifdef UNIT_TESTS

#include <gtest/gtest.h>

TEST(NegabinaryTest, SampleTest) {
    EXPECT_EQ(solve(2), 4);
    EXPECT_EQ(solve(1), 0);
    EXPECT_EQ(solve(3), -8);
    EXPECT_EQ(solve(4), 16);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
