#include <gtest/gtest.h>

using namespace std;

int minSwapsToGatherA(string_view s)
{
    const int n = static_cast<int>(s.size());
    int cntA = static_cast<int>(count(s.begin(), s.end(), 'a'));

    if (cntA == 0 || cntA == n)
        return 0;

    int currB = 0;

    for (int i = 0; i < cntA; ++i)
    {
        if (s[i] == 'b')
            ++currB;
    }

    int answer = currB;

    for (int start = 1; start < n; ++start)
    {
        if (s[(start - 1) % n] == 'b')
            --currB;
        if (s[(start + cntA - 1) % n] == 'b')
            ++currB;
        answer = min(answer, currB);
    }

    return answer;
}

TEST(SampleTests, ProvidedCases)
{
    EXPECT_EQ(minSwapsToGatherA("abababababababa"), 3);
    EXPECT_EQ(minSwapsToGatherA("ba"), 0);
    EXPECT_EQ(minSwapsToGatherA("aaaabbbbba"), 0);
    EXPECT_EQ(minSwapsToGatherA("abab"), 1);
    EXPECT_EQ(minSwapsToGatherA("aabbaaabaaba"), 2);
    EXPECT_EQ(minSwapsToGatherA("aaaa"), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}