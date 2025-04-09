#include <iostream>
#include <cmath>
#ifdef UNIT_TEST
#include <gtest/gtest.h>
#endif

using namespace std;

long long minPalindromeDigits(long long N) {
    if (N <= 9) return 1;

    long long candidate = (N + 8) / 9;
    if (candidate % 2 == 0 && N % 2 == 1) candidate++;
    return candidate;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    cout << minPalindromeDigits(N);
    return 0;
}
#endif

#ifdef UNIT_TEST
TEST(SumPalindromeTest, SampleTest1) {
    EXPECT_EQ(minPalindromeDigits(15), 3);
}

TEST(SumPalindromeTest, SampleTest2) {
    EXPECT_EQ(minPalindromeDigits(6), 1);
}

TEST(SumPalindromeTest, SampleTest3) {
    EXPECT_EQ(minPalindromeDigits(34), 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
