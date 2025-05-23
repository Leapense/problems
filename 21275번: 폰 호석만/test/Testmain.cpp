#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <string>
TEST(SampleTest, TestCase1)
{
    std::string input = "ep jh";
    std::string output = solveCase(input);
    EXPECT_EQ(output, "473 32 24");
}
TEST(SampleTest, TestCase2)
{
    std::string input = "z z";
    std::string output = solveCase(input);
    EXPECT_EQ(output, "Impossible");
}
TEST(SampleTest, TestCase3)
{
    std::string input = "0 0";
    std::string output = solveCase(input);
    EXPECT_EQ(output, "Multiple");
}
TEST(SampleTest, TestCase4)
{
    std::string input = "2222222222222222222222222222222222222222222222222222222222222222222222 8888888888888888888888888888888";
    std::string output = solveCase(input);
    EXPECT_EQ(output, "Impossible");
}
TEST(AdditionalTest, LeadingZeros)
{
    std::string input = "01 1";
    std::string output = solveCase(input);
    EXPECT_EQ(output, "Multiple");
}
TEST(AdditionalTest, DifferentCases)
{
    std::string input = "10 a";
    std::string output = solveCase(input);
    EXPECT_EQ(output, "Multiple");
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}