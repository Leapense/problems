#include <gtest/gtest.h>
#include <string>

using namespace std;

bool canTransform(const string &s, const string &t)
{
    size_t n = s.size(), m = t.size();
    if (m > n)
        return false;
    if (m == 1)
        return s.find(t[0]) != string::npos;

    for (int k = 0; (1u << k) <= n; ++k)
    {
        size_t step = 1u << k;
        for (size_t p = 0; p < step && p < n; ++p)
        {
            size_t len = (n - 1 - p) / step + 1;
            if (len != m)
                continue;
            bool ok = true;
            for (size_t j = 0, idx = p; j < m; ++j, idx += step)
                if (s[idx] != t[j])
                {
                    ok = false;
                    break;
                }
            if (ok)
                return true;
        }
    }
    return false;
}

TEST(StringSplitSample, GivenCases)
{
    EXPECT_TRUE(canTransform("tjhdoumraise", "thomas"));
    EXPECT_FALSE(canTransform("nick", "james"));
    EXPECT_TRUE(canTransform("baccba", "baccba"));
    EXPECT_FALSE(canTransform("abcdefg", "cde"));
    EXPECT_TRUE(canTransform("abcdabcd", "aa"));
    EXPECT_FALSE(canTransform("abcdabcd", "bc"));
}

TEST(StringSplitEdge, SingleChar)
{
    EXPECT_TRUE(canTransform("a", "a"));
    EXPECT_FALSE(canTransform("a", "b"));
}

TEST(StringSplitEdge, PowerOfTwo)
{
    EXPECT_TRUE(canTransform("abcdefgh", "aceg"));
    EXPECT_TRUE(canTransform("abcdefgh", "bdfh"));
    EXPECT_FALSE(canTransform("abcdefgh", "adg"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}