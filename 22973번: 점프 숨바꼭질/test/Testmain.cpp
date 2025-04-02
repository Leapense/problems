#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(MinimumJumpTest, Sample1) {
    EXPECT_EQ(minimumJumps(3), 2);
}

TEST(MinimumJumpTest, Sample2) {
    EXPECT_EQ(minimumJumps(-7), 3);
}

TEST(MinimumJumpTest, Sample3) {
    EXPECT_EQ(minimumJumps(2), -1);
}

TEST(MinimumJumpTest, ZeroCase) {
    EXPECT_EQ(minimumJumps(0), 0);
}

TEST(MinimumJumpTest, LargeOdd) {
    EXPECT_GT(minimumJumps(1000000000001LL), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
