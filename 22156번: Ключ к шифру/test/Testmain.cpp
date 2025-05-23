#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <sstream>
#include <string>

// 샘플 테스트 케이스: 문제 예제에 따른 입력과 출력 확인
TEST(DecodingTest, SampleCases) {
    // 입력: 3개의 테스트 케이스
    string input = "3\nababc\nababa\ncxbaydzabxe\n";
    // 예제 출력: 각 테스트케이스의 복호화된 키
    string expected_output = "bab\nababa\nxba\n";
    
    stringstream in(input);
    stringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), expected_output);
}

// 추가적으로 원하는 테스트 케이스를 더 추가할 수 있습니다.
TEST(DecodingTest, SingleCharacter) {
    // 한 글자만 있는 경우 항상 자기 자신이 정답입니다.
    string input = "1\na\n";
    string expected_output = "a\n";
    
    stringstream in(input);
    stringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
