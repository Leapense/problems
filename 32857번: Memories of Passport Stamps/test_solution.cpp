#define UNIT_TEST
#include "solution.cpp"
#include <gtest/gtest.h>

TEST(PassportStamps, Sample1)
{
    vector<ll> p = {9, 12, 5};
    ll k = 5;
    EXPECT_EQ(compute_min_s(p, k), 6);
}

TEST(PassportStamps, SingleSegmentOneTrip)
{
    vector<ll> p = {100};
    ll k = 1;
    EXPECT_EQ(compute_min_s(p, k), 100);
}

TEST(PassportStamps, EqualSegmentsMinTrips)
{
    vector<ll> p = {5, 5, 5};
    ll k = 3;
    EXPECT_EQ(compute_min_s(p, k), 5);
}

TEST(PassportStamps, EqualSegmentsExtraTrips)
{
    vector<ll> p = {5, 5, 5};
    ll k = 9;
    EXPECT_EQ(compute_min_s(p, k), 2);
}

TEST(PassportStamps, VeryLargeValues)
{
    vector<ll> p = {1000000000000000000LL, 1000000000000000000LL};
    ll k = 2;
    EXPECT_EQ(compute_min_s(p, k), 1000000000000000000LL);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}