#include <gtest/gtest.h>
#include <vector>

using namespace std;

pair<long long, long long> solve(const vector<long long> &h, const vector<long long> &a);

TEST(FlightPlanTest, Sample1)
{
    vector<long long> h = {6, 7, 8, 8, 7, 7};
    vector<long long> a = {10, 6, 3, 1, 1, 4};
    auto [H, cost] = solve(h, a);
    EXPECT_EQ(H, 7);
    EXPECT_EQ(cost, 14);
}

TEST(FlightPlanTest, Sample2)
{
    vector<long long> h = {7, 5, 7, 9, 8};
    vector<long long> a = {10, 8, 7, 8, 5};
    auto [H, cost] = solve(h, a);
    EXPECT_EQ(H, 7);
    EXPECT_EQ(cost, 37);
}

TEST(FlightPlanTest, Sample3)
{
    vector<long long> h = {8, 5, 10, 9, 7};
    vector<long long> a = {2, 5, 4, 8, 4};
    auto [H, cost] = solve(h, a);
    EXPECT_EQ(H, 9);
    EXPECT_EQ(cost, 34);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}