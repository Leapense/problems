#include <gtest/gtest.h>
#include <cmath>

using namespace std;

pair<double, double> solveCase(int type, double a, double b)
{
    if (type == 1)
    {
        double r = hypot(a, b);
        double theta = atan2(b, a);
        if (r == 0)
            theta = 0;
        else if (theta < 0)
            theta += 2 * M_PI;
        return {r, theta};
    }
    else
    {
        double x = a * cos(b);
        double y = a * sin(b);
        return {x, y};
    }
}

TEST(CoordinateTransform, SampleInput1)
{
    auto p1 = solveCase(1, 1.00000000, 2.00000000);
    EXPECT_NEAR(p1.first, sqrt(5.0), 1e-6);
    EXPECT_NEAR(p1.second, atan2(2.0, 1.0), 1e-6);

    auto p2 = solveCase(2, 2.23606798, 1.10714872);
    EXPECT_NEAR(p2.first, 1.0, 1e-6);
    EXPECT_NEAR(p2.second, 2.0, 1e-6);
}

TEST(CoordinateTransform, SampleInput2)
{
    auto p1 = solveCase(1, -1.00000000, -2.00000000);
    EXPECT_NEAR(p1.first, sqrt(5.0), 1e-6);
    double ang = atan2(-2.0, -1.0);
    if (ang < 0)
        ang += 2 * M_PI;
    EXPECT_NEAR(p1.second, ang, 1e-6);

    auto p2 = solveCase(2, 2.23606798, 4.24874137);
    EXPECT_NEAR(p2.first, -1.0, 1e-6);
    EXPECT_NEAR(p2.second, -2.0, 1e-6);
}

TEST(CoordinateTransform, SampleInput3)
{
    auto p1 = solveCase(1, 0.00000000, 0.00000000);
    EXPECT_DOUBLE_EQ(p1.first, 0.0);
    EXPECT_DOUBLE_EQ(p1.second, 0.0);

    auto p2 = solveCase(2, 0.00000000, 0.00000000);
    EXPECT_DOUBLE_EQ(p2.first, 0.0);
    EXPECT_DOUBLE_EQ(p2.second, 0.0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}