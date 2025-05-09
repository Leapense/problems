#include <gtest/gtest.h>
#include <string>
using namespace std;

int count_eight(string L, string R)
{
    if (L.size() != R.size())
        return 0;
    int cnt = 0;
    for (size_t i = 0; i < L.size(); ++i)
    {
        if (L[i] == R[i])
        {
            if (L[i] == '8')
                ++cnt;
        }
        else
        {
            break;
        }
    }
    return cnt;
}

TEST(SampleTest, Case1)
{
    EXPECT_EQ(count_eight("1", "10"), 0);
}

TEST(SampleTest, Case2)
{
    EXPECT_EQ(count_eight("88", "88"), 2);
}

TEST(SampleTest, Case3)
{
    EXPECT_EQ(count_eight("800", "899"), 1);
}

TEST(SampleTest, Case4)
{
    EXPECT_EQ(count_eight("8808", "8880"), 2);
}

TEST(ExtraTest, DiffLength)
{
    EXPECT_EQ(count_eight("7", "888"), 0);
}

TEST(ExtraTest, NoEight)
{
    EXPECT_EQ(count_eight("123", "129"), 0);
}

TEST(ExtraTest, AllEight)
{
    EXPECT_EQ(count_eight("8888", "8888"), 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}