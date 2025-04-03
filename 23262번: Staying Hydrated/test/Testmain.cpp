#include "../cpp/src/main.h"
#include "gtest/gtest.h"
#include <sstream>
#include <string>

// 예시 테스트 케이스: Sample Input 1 기반 테스트
TEST(SampleTests, SampleInput1) {
    std::istringstream input(R"(2
3
0 0 1 1
2 3 4 6
0 3 5 9
1
0 0 1 1
)");
    std::ostringstream output;
    solve(input, output);
    std::string expected = "Case #1: 1 3\nCase #2: 0 0\n";
    EXPECT_EQ(output.str(), expected);
}

// 추가 테스트 케이스 (원하는 경우 더 추가 가능)
TEST(AdditionalTests, SingleRectangle) {
    std::istringstream input(R"(1
1
-5 -5 5 5
)");
    std::ostringstream output;
    solve(input, output);
    // 직사각형 내부 어디든 비용은 0이므로, 후보 중 가장 작은 좌표 (-5, -5)를 선택
    std::string expected = "Case #1: -5 -5\n";
    EXPECT_EQ(output.str(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
