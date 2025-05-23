#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>

using namespace std;

TEST(SolutionTest, Sample1)
{
    ll n = 10;
    int k = 2;
    vector<Segment> segments = {{8, 10}, {3, 5}};
    EXPECT_EQ(solve(n, k, segments), 44);
}

TEST(SolutionTest, Sample2)
{
    ll n = 15;
    int k = 5;
    vector<Segment> segments = {{2, 4}, {6, 8}, {10, 12}};
    EXPECT_EQ(solve(n, k, segments), 36);
}

TEST(SolutionTest, SingleSegment)
{
    ll n = 5;
    int k = 3;
    vector<Segment> segments = {{2, 4}};
    EXPECT_EQ(solve(n, k, segments), 8);
}

TEST(SolutionTest, MultipleSegmentsNoOverlap)
{
    ll n = 100;
    int k = 10;
    vector<Segment> segments = {{90, 100}, {50, 60}};
    EXPECT_EQ(solve(n, k, segments), 302);
}

TEST(SolutionTest, FullCoverage)
{
    ll n = 10;
    int k = 1;
    vector<Segment> segments = {{1, 10}};
    EXPECT_EQ(solve(n, k, segments), 110);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}