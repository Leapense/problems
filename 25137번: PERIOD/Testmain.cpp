#include <iostream>
#include <string>
#include <numeric>
#include <cstdlib>
#include <utility>
#ifdef UNITTEST
#include <gtest/gtest.h>
#endif

using namespace std;

pair<long long, long long> convertDecimal(const string &input) {
    string s = input.substr(2);
    int L = s.size();
    int x = 0, y = 0;
    for (int candidateY = 1; candidateY * 3 <= L; candidateY++) {
        int candidateX = L - 3 * candidateY;
        string rep = s.substr(candidateX, candidateY);
        if (s.substr(candidateX + candidateY, candidateY) == rep && s.substr(candidateX + 2 * candidateY, candidateY) == rep) {
            x = candidateX;
            y = candidateY;
            break;
        }
    }
    long long numerator, denominator;

    if (x == 0) {
        long long repVal = stoll(s.substr(0, y));
        numerator = repVal;
        denominator = 1;
        for (int i = 0; i < y; i++) denominator *= 10;
        denominator -= 1;
    } else {
        long long whole = stoll(s.substr(0, x + y));
        long long nonRep = stoll(s.substr(0, x));
        numerator = whole - nonRep;
        denominator = 1;
        for (int i = 0; i < x + y; i++) denominator *= 10;
        long long nonRepDen = 1;
        for (int i = 0; i < x; i++) nonRepDen *= 10;
        denominator -= nonRepDen;
    }
    long long g = gcd(numerator, denominator);
    return {numerator / g, denominator / g};
}

#ifndef UNITTEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin >> input;
    auto res = convertDecimal(input);
    cout << res.first << "\n" << res.second << "\n";
    return 0;
}
#else
TEST(ConvertDecimalTest, Sample1) {
    auto res = convertDecimal("0.222");
    EXPECT_EQ(res.first, 2);
    EXPECT_EQ(res.second, 9);
}

TEST(ConvertDecimalTest, Sample2) {
    auto res = convertDecimal("0.252525");
    EXPECT_EQ(res.first, 25);
    EXPECT_EQ(res.second, 99);
}

TEST(ConvertDecimalTest, Sample3) {
    auto res = convertDecimal("0.123123123");
    EXPECT_EQ(res.first, 41);
    EXPECT_EQ(res.second, 333);
}

TEST(ConvertDecimalTest, Sample4) {
    auto res = convertDecimal("0.1222");
    EXPECT_EQ(res.first, 11);
    EXPECT_EQ(res.second, 90);
}

TEST(ConvertDecimalTest, Sample5) {
    auto res = convertDecimal("0.8161616");
    EXPECT_EQ(res.first, 404);
    EXPECT_EQ(res.second, 495);
}

TEST(ConvertDecimalTest, Sample6) {
    auto res = convertDecimal("0.000555");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 1800);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
