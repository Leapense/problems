#include "gtest/gtest.h"
#include "solution.cpp"

TEST(GalaxyExpressTest, Sample1)
{
    // xs=5, ys=2, xe=2, ye=1, dx=2, dy=4 -> 3 3
    Point result = calculate_jump_point(5, 2, 2, 1, 2, 4);
    Point expected = {3, 3};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, TrainStationary)
{
    // Train at (1,1), not moving. Station at (0,0). Closest is (1,1).
    Point result = calculate_jump_point(0, 0, 1, 1, 0, 0);
    Point expected = {1, 1};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, ClosestInPast)
{
    // Station at origin (0,0). Train starts at (1,0) moving along +X (away from origin).
    // t_optimal = -1. Closest on ray t>=0 is at t=0, position (1,0).
    Point result = calculate_jump_point(0, 0, 1, 0, 1, 0);
    Point expected = {1, 0};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, ClosestAtStartTime)
{
    // Station at origin (0,0). Train starts at origin (0,0) moving away.
    // t_optimal = 0. Closest is at t=0, position (0,0).
    Point result = calculate_jump_point(0, 0, 0, 0, 1, 1);
    Point expected = {0, 0};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, ClosestInFuture)
{
    // Station at origin (0,0). Train starts at (-2,-2) moving towards origin (dx=1, dy=1).
    // t_optimal = 2. Reaches origin at t=2. Closest point is (0,0).
    Point result = calculate_jump_point(0, 0, -2, -2, 1, 1);
    Point expected = {0, 0};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, StationOnPathAhead)
{
    // Station at (5,5). Train starts at (0,0) moving towards (5,5) (dx=1, dy=1).
    // t_optimal = 5. Reaches (5,5) at t=5. Closest point is (5,5).
    Point result = calculate_jump_point(5, 5, 0, 0, 1, 1);
    Point expected = {5, 5};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, StationOnPathBehindTrainMovesAway)
{
    // Station at (-5,-5). Train starts at (0,0) moving along (dx=1, dy=1) (away from station).
    // t_optimal = -5. Closest on ray t>=0 is at t=0, position (0,0).
    Point result = calculate_jump_point(-5, -5, 0, 0, 1, 1);
    Point expected = {0, 0};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, AllNegativeCoordinatesMirroredSample1)
{
    // xs=-5, ys=-2, xe=-2, ye=-1, dx=-2, dy=-4 -> -3 -3
    Point result = calculate_jump_point(-5, -2, -2, -1, -2, -4);
    Point expected = {-3, -3};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, ZeroDXTrainMovesVertically)
{
    // Station (1,5). Train path x=1, starts (1,0), moves dy=1.
    // Reaches (1,5) at t=5.
    Point result = calculate_jump_point(1, 5, 1, 0, 0, 1);
    Point expected = {1, 5};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, ZeroDYTrainMovesHorizontally)
{
    // Station (5,1). Train path y=1, starts (0,1), moves dx=1.
    // Reaches (5,1) at t=5.
    Point result = calculate_jump_point(5, 1, 0, 1, 1, 0);
    Point expected = {5, 1};
    ASSERT_EQ(result, expected);
}

TEST(GalaxyExpressTest, MaxCoordinateValues)
{
    // xs=100, ys=100, xe=-100, ye=-100, dx=1, dy=1
    // t_den = 1*1 + 1*1 = 2
    // val_xe_xs = -100 - 100 = -200
    // val_ye_ys = -100 - 100 = -200
    // dot_prod = (-200)*1 + (-200)*1 = -400
    // t_num = -(-400) = 400
    // t_optimal = 400/2 = 200. (t_num >= 0)
    // jump_x_num = (-100)*2 + 400*1 = -200 + 400 = 200. jump_x = 200/2 = 100.
    // jump_y_num = (-100)*2 + 400*1 = -200 + 400 = 200. jump_y = 200/2 = 100.
    // Expected (100,100)
    Point result = calculate_jump_point(100, 100, -100, -100, 1, 1);
    Point expected = {100, 100};
    ASSERT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}