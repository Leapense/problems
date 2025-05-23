#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <sstream>
#include <string>

// 테스트를 위한 헬퍼 함수: 입력 m에 대해 solveScales의 결과를 문자열 형태로 반환
std::string formatOutput(const std::pair<std::vector<std::string>, std::vector<std::string>> &res) {
    std::ostringstream oss;
    const auto &left = res.first;
    const auto &right = res.second;
    oss << left.size();
    for(const auto &s : left)
        oss << " " << s;
    oss << "\n";
    oss << right.size();
    for(const auto &s : right)
        oss << " " << s;
    oss << "\n";
    return oss.str();
}

// 샘플 테스트 케이스 1: m = 42
TEST(ScalesTest, SampleTest1) {
    std::string m = "42";
    auto res = solveScales(m);
    // 예상: 좌측: { "3", "9", "27" }, 우측: { "81" }
    std::string expected = "3 3 9 27\n1 81\n";
    EXPECT_EQ(formatOutput(res), expected);
}

// 샘플 테스트 케이스 2: m = 30
TEST(ScalesTest, SampleTest2) {
    std::string m = "30";
    auto res = solveScales(m);
    // 예상: 좌측: {} , 우측: { "3", "27" }
    std::string expected = "0\n2 3 27\n";
    EXPECT_EQ(formatOutput(res), expected);
}

// 추가 테스트: m = 1
TEST(ScalesTest, EdgeTest) {
    std::string m = "1";
    auto res = solveScales(m);
    // 예상: 좌측: {} , 우측: { "1" }
    std::string expected = "0\n1 1\n";
    EXPECT_EQ(formatOutput(res), expected);
}

#ifndef UNIT_TEST
// main 함수는 main.cpp에 있으므로, 여기서는 필요 없음.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
