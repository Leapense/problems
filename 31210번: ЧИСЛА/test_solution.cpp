#include <gtest/gtest.h>
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

/* find_number 함수 선언 (solution.cpp 에 정의) */
ull find_number(ull, int);

TEST(NumbersTest, Sample0)
{
    EXPECT_EQ(find_number(700, 0), 777ULL);
}

TEST(NumbersTest, Sample1)
{
    EXPECT_EQ(find_number(700, 1), 700ULL);
}

TEST(NumbersTest, RepdigitBigger)
{
    EXPECT_EQ(find_number(1234, 0), 2222ULL);
}

TEST(NumbersTest, EdgeMax)
{
    ull x = 99999999999999999ULL;    // 17자리 9
    EXPECT_EQ(find_number(x, 0), x); // 이미 만족
}

TEST(NumbersTest, OneDiffNeedsNextLen)
{
    // 998…8 (17자리) 다음으로 조건 k=1 을 만족하는 수는 999…9 (17자리) 자체
    string s(17, '9');     // "999...9"
    ull x = stoull(s) - 1; // 999...8
    EXPECT_EQ(find_number(x, 1), stoull(s));
}