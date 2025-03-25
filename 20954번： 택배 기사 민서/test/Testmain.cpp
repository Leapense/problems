#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(DeliveryRouteTest, SampleCases)
{
    DeliveryRoute route;
    EXPECT_EQ(route.solveQuery(0), 0);
    EXPECT_EQ(route.solveQuery(1), 1);
    EXPECT_EQ(route.solveQuery(2), 6);
    EXPECT_EQ(route.solveQuery(3), 15);
    EXPECT_EQ(route.solveQuery(4), 16);
}

TEST(DeliveryRouteTest, NegativeCoordinates)
{
    DeliveryRoute route;
    EXPECT_EQ(route.solveQuery(-1), 3);
    EXPECT_EQ(route.solveQuery(-2), 10);
}

TEST(DeliveryRouteTest, LargeCoordinates)
{
    DeliveryRoute route;

    int64_t largePos = 1LL << 30;
    int64_t resultPos = route.solveQuery(largePos);
    int64_t largeNeg = -(1LL << 30);
    int64_t resultNeg = route.solveQuery(largeNeg);
    EXPECT_GT(resultPos, 0);
    EXPECT_GT(resultNeg, 0);
    EXPECT_NE(resultPos, resultNeg);
}

TEST(DeliveryRouteTest, MidSegmentCoordinates)
{
    DeliveryRoute route;
    EXPECT_EQ(route.solveQuery(0), 0);
    EXPECT_EQ(route.solveQuery(1), 1);
    EXPECT_EQ(route.solveQuery(2), 6);
    EXPECT_EQ(route.solveQuery(0), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}