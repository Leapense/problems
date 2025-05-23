#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>
#include <string>

// 샘플 테스트 케이스 1: 문제 설명에 있는 예제
TEST(HillCipherTest, SampleTest1)
{
    int n = 3;
    std::vector<std::vector<int>> matrix = {
        {30, 1, 9},
        {4, 23, 7},
        {5, 9, 13}};
    std::string plaintext = "ATTACK AT DAWN";
    std::string expected = "FPLSFA4SUK2W9K3";

    std::string result = HillCipher::encrypt(matrix, plaintext);
    EXPECT_EQ(result, expected);
}

// 샘플 테스트 케이스 2: 문제 설명에 있는 두 번째 예제
TEST(HillCipherTest, SampleTest2)
{
    int n = 6;
    std::vector<std::vector<int>> matrix = {
        {26, 11, 23, 14, 13, 16},
        {6, 7, 32, 4, 29, 29},
        {26, 19, 30, 10, 30, 11},
        {6, 28, 23, 5, 24, 23},
        {6, 24, 1, 27, 24, 20},
        {13, 9, 32, 18, 20, 18}};
    std::string plaintext = "MY HOVERCRAFT IS FULL OF EELS";
    std::string expected = "W4QVBO0NJG5 Y76H5A6XHR11BV670Z";

    std::string result = HillCipher::encrypt(matrix, plaintext);
    EXPECT_EQ(result, expected);
}

// 추가 테스트 케이스 1: 1x1 행렬 테스트 (단일 원소 행렬)
TEST(HillCipherTest, SingleElementMatrix)
{
    int n = 1;
    std::vector<std::vector<int>> matrix = {{5}};
    // 평문 "ABC"에 대해 각 문자를 5배한 후 mod 37
    // A(0) -> 0 -> 'A', B(1) -> 5 -> 'F', C(2) -> 10 -> 'K'
    std::string plaintext = "ABC";
    std::string expected = "AFK";

    std::string result = HillCipher::encrypt(matrix, plaintext);
    EXPECT_EQ(result, expected);
}

// 추가 테스트 케이스 2: 2x2 행렬 테스트 (패딩 없음)
TEST(HillCipherTest, TwoByTwoMatrix_NoPadding)
{
    int n = 2;
    std::vector<std::vector<int>> matrix = {
        {1, 2},
        {3, 4}};
    // "HI" → H:7, I:8
    // 결과: [1*7+2*8 = 23, 3*7+4*8 = 53 mod37 = 16] → 23 → 'X', 16 → 'Q'
    std::string plaintext = "HI";
    std::string expected = "XQ";

    std::string result = HillCipher::encrypt(matrix, plaintext);
    EXPECT_EQ(result, expected);
}

// 추가 테스트 케이스 3: 빈 평문 테스트
TEST(HillCipherTest, EmptyPlaintext)
{
    int n = 3;
    std::vector<std::vector<int>> matrix = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    std::string plaintext = "";
    std::string expected = ""; // 빈 평문은 그대로 빈 암호문

    std::string result = HillCipher::encrypt(matrix, plaintext);
    EXPECT_EQ(result, expected);
}

// 추가 테스트 케이스 4: 패딩이 필요한 경우 (2x2 행렬)
TEST(HillCipherTest, TwoByTwoMatrix_WithPadding)
{
    int n = 2;
    std::vector<std::vector<int>> matrix = {
        {2, 3},
        {1, 4}};
    // 평문 "TESTS" 길이 5 → 패딩되어 6글자가 됨.
    // 먼저 문자 매핑: T:19, E:4, S:18, T:19, S:18, (space):36
    // 그룹 1: (19,4) → row0:2*19+3*4=38+12=50 mod37=13 → 'N'; row1:1*19+4*4=19+16=35 → '9'
    // 그룹 2: (18,19) → row0:2*18+3*19=36+57=93 mod37=93-74=19 → 'T'; row1:1*18+4*19=18+76=94 mod37=94-74=20 → 'U'
    // 그룹 3: (18,36) → row0:2*18+3*36=36+108=144 mod37=144-111=33 → '7' (33-26=7); row1:1*18+4*36=18+144=162 mod37=162-148=14 → 'O'
    // 최종 암호문: "N9TU7O"
    std::string plaintext = "TESTS";
    std::string expected = "N9TU7O";

    std::string result = HillCipher::encrypt(matrix, plaintext);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
