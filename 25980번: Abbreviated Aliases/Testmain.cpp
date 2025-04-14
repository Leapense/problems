#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int commonPrefixLength(const string &a, const string &b) {
    int len = 0;
    int minSize = min(a.size(), b.size());
    while (len < minSize && a[len] == b[len]) {
        len++;
    }

    return len;
}

int computeTotalCharacters(int n, int l, const vector<string>& aliases) {
    vector<string> sorted_aliases = aliases;
    sort(sorted_aliases.begin(), sorted_aliases.end());

    long long totalCharacters = 0;

    for (int i = 0; i < n; i++) {
        int requiredPrefix = 0;
        if (i > 0) {
            requiredPrefix = max(requiredPrefix, commonPrefixLength(sorted_aliases[i], sorted_aliases[i - 1]) + 1);
        }

        if (i < n - 1) {
            requiredPrefix = max(requiredPrefix, commonPrefixLength(sorted_aliases[i], sorted_aliases[i + 1]) + 1);
        }

        if (requiredPrefix > l) {
            requiredPrefix = l;
        }

        totalCharacters += requiredPrefix;
    }

    return static_cast<int>(totalCharacters);
}

TEST(CompressedAliasesTest, Sample1) {
    int n = 2, l = 5;
    vector<string> aliases = {"james", "jacob"};
    EXPECT_EQ(computeTotalCharacters(n, l, aliases), 6);
}

TEST(CompressedAliasesTest, Sample2) {
    int n = 4, l = 4;
    vector<string> aliases = {"xxxx", "yxxx", "xxyx", "yxxy"};
    EXPECT_EQ(computeTotalCharacters(n, l, aliases), 14);
}

TEST(CompressedAliasesTest, AllDifferent) {
    int n = 3, l = 3;
    vector<string> aliases = {"abc", "def", "ghi"};
    EXPECT_EQ(computeTotalCharacters(n, l, aliases), 3);
}

TEST(CompressedAliasesTest, LongCommonPrefix) {
    int n = 3, l = 10;
    vector<string> aliases = {"abcdefghij", "abcdefgxyz", "abcdeflmnq"};
    int result = computeTotalCharacters(n, l, aliases);
    EXPECT_GT(result, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}