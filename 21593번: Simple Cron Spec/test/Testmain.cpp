#include "../cpp/src/main.h"
#include "gtest/gtest.h"
#include <sstream>
#include <string>

TEST(CronSpecTest, SampleTest)
{
    string input = "2\n* 30 20,25,30-33\n9,15 30 *\n";
    string expected = "252 264";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

TEST(CronSpecTest, FullDayTest)
{
    string input = "1\n* * *\n";
    string expected = "86400 86400";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

TEST(CronSpecTest, RangeTest)
{
    string input = "1\n9-10 10-11 10-11\n";
    string expected = "8 8";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

TEST(CronSpecTest, MultipleSpecsOverlapTest)
{
    string input = "2\n9 10 15\n9 10 15\n";
    string expected = "1 2";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

TEST(CronSpecTest, MixedSpecTest)
{
    string input = "1\n9,10,11 0,30,59 15,30,45\n";
    string expected = "27 27";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}