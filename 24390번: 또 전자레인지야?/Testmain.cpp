#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>

using namespace std;

int minPresses(const string& timeStr) {
    int M = stoi(timeStr.substr(0, 2));
    int S = stoi(timeStr.substr(3, 2));
    int T = M * 60 + S;

    int option1 = 0;
    int temp = T;
    option1 += temp / 600; temp %= 600;
    option1 += temp / 60; temp %= 60;
    option1 += temp / 10;
    option1 += 1;

    int option2 = 1e9;
    if (T >= 30) {
        int remaining = T - 30;
        int count = 0;

        count += remaining / 600; remaining %= 600;
        count += remaining / 60; remaining %= 60;
        count += remaining / 30; remaining %= 30;
        count += remaining / 10;
        option2 = 1 + count;
    }

    return min(option1, option2);
}

TEST(MicrowaveTest, SampleTest) {
    // 예제: "02:00" -> 3번
    EXPECT_EQ(minPresses("02:00"), 3);
}

TEST(MicrowaveTest, CaseExactly30Seconds) {
    // "00:30" 의 경우 Option2: 바로 조리시작 버튼만 눌러 30초 확보 → 1번, Option1: 10초 버튼 3회 + 조리시작 → 4번
    EXPECT_EQ(minPresses("00:30"), 1);
}

TEST(MicrowaveTest, CaseComplex) {
    // 예를 들어 "06:40" (400초)
    // Option1: 400초 = 0*600 + 6*60(360초) + 4*10(40초) + 조리시작 = 6+4+1 = 11번
    // Option2: 400-30=370초 = 0*600 + 6*60(360초) + 1*10(10초) = 6+0+0+1 +1(첫 조리시작) = 8번
    EXPECT_EQ(minPresses("06:40"), 8);
}

TEST(MicrowaveTest, MinimumTime) {
    // 최소 조리시간인 10초 -> Option1: 10초 버튼 1회 + 조리시작 = 2번
    // Option2: T < 30 이므로 사용 불가.
    EXPECT_EQ(minPresses("00:10"), 2);
}

TEST(MicrowaveTest, MaximumTime) {
    // 최대 조리시간 60분 = 3600초
    // Option1: 3600 / 600 = 6, 남은 시간 0, 조리시작 = 6 + 1 = 7번.
    // Option2: 3600-30 = 3570초, 계산 시 더 많은 버튼이 필요할 것으로 예상됨.
    EXPECT_EQ(minPresses("60:00"), 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
