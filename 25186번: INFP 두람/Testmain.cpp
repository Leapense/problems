#include <gtest/gtest.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

string isHappy(const vector<int> &clothes)
{
    long long total = accumulate(clothes.begin(), clothes.end(), 0LL);
    int max_count = *max_element(clothes.begin(), clothes.end());
    return (max_count <= (total + 1) / 2) ? "Happy" : "Unhappy";
}

TEST(DooramTest, SampleInput1)
{
    vector<int> clothes = {1, 5, 4, 1, 2};
    EXPECT_EQ(isHappy(clothes), "Happy");
}

TEST(DooramTest, SampleInput2)
{
    vector<int> clothes = {7, 1, 5, 7, 4};
    EXPECT_EQ(isHappy(clothes), "Happy");
}

TEST(DooramTest, SampleInput3)
{
    vector<int> clothes = {1, 13, 2, 4, 1, 1, 1};
    EXPECT_EQ(isHappy(clothes), "Unhappy");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
