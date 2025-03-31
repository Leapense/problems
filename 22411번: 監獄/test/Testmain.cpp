#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(SampleTests, TestCase1) {
    std::istringstream iss("4 2");
    std::ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), "7");
}

TEST(SampleTests, TestCase2) {
    std::istringstream iss("1 3");
    std::ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), "0");
}

TEST(SampleTests, TestCase3) {
    std::istringstream iss("100000 100000");
    std::ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), "99999");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
