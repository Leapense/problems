#include <iostream>
#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>

int maxReceipts(int x, int y)
{
    int r_max = (2 * x + 3 * y) / 100;
    int ans = 0;

    for (int r = 0; r <= r_max; r++)
    {
        int S_lower = std::max(0, (int)ceil((50.0 * r - x) / 3.0));
        int S_upper = std::min(16 * r, y / 2);
        if (S_lower <= S_upper)
        {
            ans = r;
        }
    }

    return ans;
}

TEST(KingOfCansTest, SampleTest1)
{
    EXPECT_EQ(maxReceipts(5, 30), 1);
}

TEST(KingOfCansTest, SampleTest2)
{
    EXPECT_EQ(maxReceipts(49, 1), 0);
}

TEST(KingOfCansTest, SampleTest3)
{
    EXPECT_EQ(maxReceipts(0, 100), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}