#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <sstream>
#include <string>

TEST(ImageProcessingTest, SampleTest1)
{
    std::string input = "3 3\n255 255 255 100 100 100 255 255 255\n"
                        "100 100 100 255 255 255 100 100 100\n"
                        "255 255 255 100 100 100 255 255 255\n101\n";
    std::stringstream ss(input);
    std::stringstream output;
    solve(ss, output);
    EXPECT_EQ(output.str(), "5");
}

TEST(ImageProcessingTest, SampleTest2)
{
    std::string input = "2 2\n124 150 123 100 100 100\n103 103 103 183 5 3\n255\n";
    std::stringstream ss(input);
    std::stringstream output;
    solve(ss, output);
    EXPECT_EQ(output.str(), "0");
}

TEST(ImageProcessingTest, AllWhiteTest)
{
    std::string input = "2 3\n255 255 255 255 255 255 255 255 255\n"
                        "255 255 255 255 255 255 255 255 255\n200\n";
    std::stringstream ss(input);
    std::stringstream output;
    solve(ss, output);
    EXPECT_EQ(output.str(), "1");
}

TEST(ImageProcessingTest, AllBlackTest)
{
    std::string input = "2 2\n0 0 0 0 0 0\n0 0 0 0 0 0\n1\n";
    std::stringstream ss(input);
    std::stringstream output;
    solve(ss, output);
    EXPECT_EQ(output.str(), "0");
}

TEST(ImageProcessingTest, MultipleObjectsTest)
{
    std::string input = "3 3\n255 255 255 0 0 0 255 255 255\n"
                        "0 0 0 0 0 0 0 0 0\n"
                        "255 255 255 0 0 0 255 255 255\n100\n";
    std::stringstream ss(input);
    std::stringstream output;
    solve(ss, output);
    EXPECT_EQ(output.str(), "4");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}