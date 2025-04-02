#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <sstream>

TEST(RPGTest, SampleTest1) {
    std::istringstream iss("10 5 100 1\n1 1\n");
    std::ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), "gg");
}

TEST(RPGTest, SampleTest2) {
    std::istringstream iss("10 7 50 1\n30 10\n");
    std::ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), "Victory!");
}

TEST(RPGTest, AdditionalTest) {
    std::istringstream iss("100 1000 500 10\n100 50\n");
    std::ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), "Victory!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
