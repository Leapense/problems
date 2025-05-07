#include <gtest/gtest.h>
#include <string>

using namespace std;

long long minimal_k(const string &target)
{
    size_t need = target.size(), pos = 0;
    long long k = 0;
    while (pos < need)
    {
        ++k;
        string s = to_string(k);
        for (char c : s)
        {
            if (c == target[pos])
            {
                ++pos;
                if (pos == need)
                    break;
            }
        }
    }

    return k;
}

TEST(Samples, Provided)
{
    EXPECT_EQ(minimal_k("90"), 10);
    EXPECT_EQ(minimal_k("00"), 20);
}

TEST(Basic, SingleDigit)
{
    EXPECT_EQ(minimal_k("7"), 7);
    EXPECT_EQ(minimal_k("0"), 10);
}

TEST(Basic, Consecutive)
{
    EXPECT_EQ(minimal_k("123456789"), 9);
}

TEST(Repeats, ManyNines)
{
    EXPECT_EQ(minimal_k(string(5, '9')), 49);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}