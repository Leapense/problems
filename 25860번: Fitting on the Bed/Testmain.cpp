#include <iostream>
#include <cmath>
#include <numbers>
#include "gtest/gtest.h"

bool fitsOnBed(int L, int W, int H, int x, int y, int a) {
    double rad = a * std::numbers::pi / 180.0;

    double tailX = x + H * std::cos(rad);
    double tailY = y + H * std::sin(rad);

    return (tailX >= 0.0 && tailX <= W && tailY >= 0.0 && tailY <= L);
}

TEST(FitsOnBedTest, SampleTestCase1) {
    EXPECT_FALSE(fitsOnBed(200, 150, 115, 40, 190, 0));
}

TEST(FitsOnBedTest, SampleTestCase2) {
    EXPECT_TRUE(fitsOnBed(200, 150, 115, 40, 150, 315));
}

TEST(FitsOnBedTest, BoundaryTest) {
    EXPECT_TRUE(fitsOnBed(200, 150, 50, 75, 200, 270));
}

TEST(FitsOnBedTest, CornerTouchTest) {
    EXPECT_TRUE(fitsOnBed(200, 150, 150, 0, 0, 0));
}

TEST(FitsOnBedTest, DiagonalTest) {
    EXPECT_TRUE(fitsOnBed(100, 100, 100, 0, 0, 45));
    EXPECT_FALSE(fitsOnBed(100, 100, 150, 0, 0, 45));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}