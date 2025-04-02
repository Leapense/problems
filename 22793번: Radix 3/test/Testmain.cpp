#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(GSCTest, Zero) {
    EXPECT_EQ(toGSC(0), "0");
}

TEST(GSCTest, PositiveNumbers) {
    EXPECT_EQ(toGSC(10), "101");
    EXPECT_EQ(toGSC(2), "1-");
    EXPECT_EQ(toGSC(42), "1---0");
    EXPECT_EQ(toGSC(1024), "111-0-1");
}

TEST(GSCTest, NegativeNumbers) {
    EXPECT_EQ(toGSC(-17), "-101");
    EXPECT_EQ(toGSC(-2), "-1");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
