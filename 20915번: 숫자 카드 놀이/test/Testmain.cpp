#include "gtest/gtest.h"
#include "../cpp/src/main.h"

// 문제 샘플 케이스 및 추가 케이스

TEST(NumberCardGameTest, SampleCase1)
{
    // "90000" -> 한 그룹이 0을 포함하여 어떤 분할이더라도 곱이 0임.
    EXPECT_EQ(getMaxProduct("90000"), 0);
}

TEST(NumberCardGameTest, SampleCase2)
{
    // "66" -> 두 카드를 각각 6->9, 6->9로 취급 => 9*9 = 81.
    EXPECT_EQ(getMaxProduct("66"), 81);
}

TEST(NumberCardGameTest, SampleCase3)
{
    // "102030" -> 최대값 예시: 21000 * 3 = 63000.
    EXPECT_EQ(getMaxProduct("102030"), 63000);
}

TEST(NumberCardGameTest, SampleCase4)
{
    // "20202021" -> 문제 예시에서 최대값 4862000.
    EXPECT_EQ(getMaxProduct("20202021"), 4862000);
}

TEST(NumberCardGameTest, SampleCase5)
{
    // "999999999999999999" -> 모든 카드가 9일 때 최대 곱.
    EXPECT_EQ(getMaxProduct("999999999999999999"), 999999998000000001LL);
}

// 추가 케이스

TEST(NumberCardGameTest, TwoDigitCase)
{
    // "12" -> 1과 2만 있을 때 최대 곱: 1*2 = 2.
    EXPECT_EQ(getMaxProduct("12"), 2);
}

TEST(NumberCardGameTest, CaseWithZeroAndNonZero)
{
    // "60" -> '6' -> '9'와 '0' => (9)와 (0) = 0.
    EXPECT_EQ(getMaxProduct("60"), 0);
}

TEST(NumberCardGameTest, ThreeDigitCase)
{
    // "123" -> 가능한 분할 중 최대는 3 * 21 = 63.
    EXPECT_EQ(getMaxProduct("123"), 63);
}

TEST(NumberCardGameTest, AllSameDigits)
{
    // "555" -> 분할: 한 그룹 "5", 다른 그룹 "55" => 5*55 = 275.
    EXPECT_EQ(getMaxProduct("555"), 275);
}

// gtest main 함수 (UNIT_TEST 매크로가 정의되어 있을 때)
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}