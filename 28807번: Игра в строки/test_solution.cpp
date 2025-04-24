#include <gtest/gtest.h>
#include <string>
#include <array>
using namespace std;

bool canPlay(int k, const string& s, const string& t) {
    int n = s.size(), m = t.size();
    if (n < k || m < k) return false;
    array<int, 26> ft{}, fw{};
    for (char c : t) ft[c - 'a']++;
    for (int i = 0; i < k; i++) fw[s[i] - 'a']++;
    auto ok = [&]() {
        for (int i = 0; i < 26; i++) if (fw[i] > ft[i]) return false;
        return true;
    };

    if (ok()) return true;
    for (int i = k; i < n; i++) {
        fw[s[i - k] - 'a']--;
        fw[s[i] - 'a']++;
        if (ok()) return true;
    }

    return false;
}

TEST(CanPlayTest, Sample1) {
    EXPECT_TRUE(canPlay(3, "aba", "bbaa"));
}

TEST(CanPlayTest, ExactMatch) {
    EXPECT_FALSE(canPlay(4, "abcd", "abc"));
    EXPECT_TRUE(canPlay(2, "xyz", "zxy"));
}

TEST(CanPlayTest, NoPossible) {
    EXPECT_FALSE(canPlay(5, "aaaaa", "aaaab"));
}

TEST(CanPlayTest, Large) {
    string s(300000, 'a'), t(300000, 'a');
    EXPECT_TRUE(canPlay(300000, s, t));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
