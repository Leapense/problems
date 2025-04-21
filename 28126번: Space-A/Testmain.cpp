#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

int countReachable(const string &s, const vector<pair<int, int>> &pts)
{
    long long cntR = 0, cntU = 0, cntX = 0;
    for (char c : s)
    {
        if (c == 'R')
            ++cntR;
        else if (c == 'U')
            ++cntU;
        else if (c == 'X')
            ++cntX;
    }

    int ans = 0;
    for (auto [x, y] : pts)
    {
        long long needX = x - 1, needY = y - 1;
        long long L = max({0LL, needX - cntR, needY - cntU});
        long long U = min({cntX, needX, needY});
        if (L <= U)
            ++ans;
    }
    return ans;
}

TEST(SpaceATest, Sample1)
{
    string s = "UUXRX";
    vector<pair<int, int>> pts = {
        {1, 3}, {2, 4}, {3, 2}, {4, 3}, {4, 5}};
    EXPECT_EQ(countReachable(s, pts), 5);
}

TEST(SpaceATest, Sample2)
{
    string s = "UUXRX";
    vector<pair<int, int>> pts = {
        {1, 4}, {2, 5}, {3, 1}, {4, 2}, {5, 3}};
    EXPECT_EQ(countReachable(s, pts), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}