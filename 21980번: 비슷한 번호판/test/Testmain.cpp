#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

// 샘플 테스트 케이스 1
TEST(CarLicensePlatesTest, SampleCase1)
{
    // 문제 예시: ["AtY", "YtA", "aTy", "Ayt"]
    vector<string> plates = {"AtY", "YtA", "aTy", "Ayt"};
    // 첫 번째와 두 번째, 그리고 세 번째와 네 번째가 유사하므로 총 2쌍
    EXPECT_EQ(countSimilarPlates(plates), 2);
}

// 샘플 테스트 케이스 2
TEST(CarLicensePlatesTest, SampleCase2)
{
    // 예시: ["AAaa", "AaAa", "aaAA", "AaaA"]
    vector<string> plates = {"AAaa", "AaAa", "aaAA", "AaaA"};
    // 모든 쌍이 유사하므로 조합: 4*(4-1)/2 = 6
    EXPECT_EQ(countSimilarPlates(plates), 6);
}

// 샘플 테스트 케이스 3
TEST(CarLicensePlatesTest, SampleCase3)
{
    // 예시: ["AAAA", "aaaa", "AAaa", "AAAa", "Aaaa"]
    vector<string> plates = {"AAAA", "aaaa", "AAaa", "AAAa", "Aaaa"};
    // 대문자 개수가 모두 다르므로 유사한 쌍이 없음
    EXPECT_EQ(countSimilarPlates(plates), 0);
}

// 샘플 테스트 케이스 4
TEST(CarLicensePlatesTest, SampleCase4)
{
    // 예시: 10개의 1글자 번호판: ["A", "a", "B", "b", "C", "c", "D", "d", "E", "e"]
    vector<string> plates = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e"};
    // 각 번호판은 알파벳이 다르므로 유사한 쌍이 없음
    EXPECT_EQ(countSimilarPlates(plates), 0);
}

// 샘플 테스트 케이스 5
TEST(CarLicensePlatesTest, SampleCase5)
{
    // 예시: ["ABCDEabcde", "abcdeEDCBA"]
    vector<string> plates = {"ABCDEabcde", "abcdeEDCBA"};
    // 두 번호판은 유사하므로 쌍의 수는 1
    EXPECT_EQ(countSimilarPlates(plates), 1);
}

// 추가 테스트 케이스 1: 번호판이 하나인 경우
TEST(CarLicensePlatesTest, SinglePlate)
{
    vector<string> plates = {"AbCdE"};
    EXPECT_EQ(countSimilarPlates(plates), 0);
}

// 추가 테스트 케이스 2: 여러 번호판 중 일부만 유사한 경우
TEST(CarLicensePlatesTest, MixedPlates)
{
    // 두 그룹: 그룹1: ["Abc", "cBa", "bAc"] => 모두 동일한 알파벳 빈도 및 대문자 개수 (1개씩)
    // 그룹2: ["ABC", "BCA"] => 대문자 개수 3인 그룹
    vector<string> plates = {"Abc", "cBa", "bAc", "ABC", "BCA", "XyZ"};
    // 그룹1: 조합: 3*(3-1)/2 = 3, 그룹2: 2*(2-1)/2 = 1, "XyZ"은 단독 -> 총 4쌍
    EXPECT_EQ(countSimilarPlates(plates), 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}