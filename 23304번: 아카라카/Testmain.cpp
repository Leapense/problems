#include <gtest/gtest.h>
#include <string>
using namespace std;

// 아카라카 판별 함수 정의
bool isAkaraka(const string& s, int left, int right) {
    int l = left, r = right;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l; --r;
    }

    int len = right - left + 1;
    if (len <= 1) return true;

    int mid = len / 2;
    return isAkaraka(s, left, left + mid - 1) &&
           isAkaraka(s, right - mid + 1, right);
}

bool isAkarakaWrapper(const string& s) {
    return isAkaraka(s, 0, s.size() - 1);
}

// 유닛 테스트 그룹
TEST(AkarakaTest, BasicCases) {
    EXPECT_TRUE(isAkarakaWrapper("a"));
    EXPECT_TRUE(isAkarakaWrapper("aka"));
    EXPECT_TRUE(isAkarakaWrapper("akaraka"));
    EXPECT_TRUE(isAkarakaWrapper("aaaaaaa"));
}

TEST(AkarakaTest, FailingCases) {
    EXPECT_FALSE(isAkarakaWrapper("akbrbka"));
    EXPECT_FALSE(isAkarakaWrapper("abc"));
    EXPECT_FALSE(isAkarakaWrapper("racecarx"));
    EXPECT_FALSE(isAkarakaWrapper("akakaak"));
}

TEST(AkarakaTest, EdgeCases) {
    EXPECT_TRUE(isAkarakaWrapper("b"));        // 길이 1
    EXPECT_TRUE(isAkarakaWrapper("bb"));       // 짝수 길이 팰린드롬
    EXPECT_FALSE(isAkarakaWrapper("ab"));      // 짝수 길이 비팰린드롬
    EXPECT_FALSE(isAkarakaWrapper("aabb"));    // 접두사/접미사에서 실패
}

