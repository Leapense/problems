#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(SampleTests, BasicTests) {
    EXPECT_EQ(solveCase(1, 3, 1), "Yes");
    EXPECT_EQ(solveCase(1, 2, 0), "No");
    EXPECT_EQ(solveCase(4, 4, 0), "Yes");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
