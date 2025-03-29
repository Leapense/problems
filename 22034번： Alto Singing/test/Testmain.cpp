#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <sstream>
#include <string>

// Function prototypes
// Sample Test Case 1
TEST(TransposeTest, SampleTest1)
{
    std::istringstream input("14\nF3 F5\nC4 C4 G4 G4 A4 A4 G4 F4 F4 E4 E4 D4 D4 C4\n");
    std::ostringstream output;
    solve(input, output);
    std::string expected = "0 3\n";
    EXPECT_EQ(output.str(), expected);
}

// Sample Test Case 2
TEST(TransposeTest, SampleTest2)
{
    std::istringstream input("1\nC#1 A#1\nC1000000000\n");
    std::ostringstream output;
    solve(input, output);
    std::string expected = "0 5\n";
    EXPECT_EQ(output.str(), expected);
}

// Sample Test Case 3
TEST(TransposeTest, SampleTest3)
{
    std::istringstream input("3\nF3 F5\nF3 F#3 F5\n");
    std::ostringstream output;
    solve(input, output);
    std::string expected = "1 1\n";
    EXPECT_EQ(output.str(), expected);
}

// 추가 테스트 케이스 1: 단일 음, 범위와 정확히 일치
TEST(TransposeTest, SingleNoteExactRange)
{
    std::istringstream input("1\nC1 C1\nC1\n");
    std::ostringstream output;
    solve(input, output);
    std::string expected = "0 1\n";
    EXPECT_EQ(output.str(), expected);
}

// 추가 테스트 케이스 2: 여러 음, 넓은 음역으로 여러 전조 가능
TEST(TransposeTest, WideRangeMultipleTranspositions)
{
    // 예: 악보 "C4 D4 E4", 범위 "C3" ~ "C6"
    // C4 = 36, D4 = 37, E4 = 38, C3 = 24, C6 = 60
    // 각 음에 대해 t ∈ [L-p, R-p]이면,
    // p=36: t ∈ [-12, 24], p=37: t ∈ [-13, 23], p=38: t ∈ [-14, 22]
    // 유효한 t 범위: [-12, 22]
    // residue r = 0일 때: 음들이 "C, D, E" (우연표 없음)이며, [-12,22]에서 r=0인 t의 개수는 3개(-12, 0, 12)
    std::istringstream input("3\nC3 C6\nC4 D4 E4\n");
    std::ostringstream output;
    solve(input, output);
    std::string expected = "0 3\n";
    EXPECT_EQ(output.str(), expected);
}

// 추가 테스트 케이스 3: 우연표가 포함된 음
TEST(TransposeTest, NonZeroAccidentals)
{
    // 예: 악보 "C#4", 범위 "C4" ~ "C5" -> 유효한 전조는 0뿐이며, C#4는 우연표 1개
    std::istringstream input("1\nC4 C5\nC#4\n");
    std::ostringstream output;
    solve(input, output);
    std::string expected = "1 1\n";
    EXPECT_EQ(output.str(), expected);
}

// Main function
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
