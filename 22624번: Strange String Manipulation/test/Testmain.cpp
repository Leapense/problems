#include "../cpp/src/main.h"
#include "gtest/gtest.h"
#include <sstream>

TEST(LCGTest, SampleTest1) {
    std::istringstream input("5\n5 4 3 2 1\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "0 1 1");
}

TEST(LCGTest, SampleTest2) {
    std::istringstream input("5\n7 7 7 7 7\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "0 0 0");
}

TEST(LCGTest, SampleTest3) {
    std::istringstream input("10\n186 8 42 24 154 40 10 56 122 72\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "8 7 14");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
