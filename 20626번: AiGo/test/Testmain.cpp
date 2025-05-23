#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <string>

TEST(OneDGoTest, SampleTest1)
{
    std::string board = ".WB..";
    EXPECT_EQ(solve_1d_go(board), 1);
}

TEST(OneDGoTest, SampleTest2)
{
    std::string board = ".WBB.";
    EXPECT_EQ(solve_1d_go(board), 2);
}

TEST(OneDGoTest, SampleTest3)
{
    std::string board = ".WB.B.";
    EXPECT_EQ(solve_1d_go(board), 3);
}

TEST(OneDGoTest, SampleTest4)
{
    std::string board = ".WB.WB";
    EXPECT_EQ(solve_1d_go(board), 0);
}

TEST(OneDGoTest, SampleTest5)
{
    std::string board = "BBB..";
    EXPECT_EQ(solve_1d_go(board), 0);
}

TEST(OneDGoTest, AllEmptyBoard)
{
    std::string board = ".....";
    EXPECT_EQ(solve_1d_go(board), 0);
}

TEST(OneDGoTest, MultipleCapturePossibility)
{
    std::string board = "WBB..BB.";
    EXPECT_EQ(solve_1d_go(board), 2);
}

TEST(OneDGoTest, IllegalMovePreventsCapture)
{
    std::string board = "B..B";
    EXPECT_EQ(solve_1d_go(board), 0);
}

TEST(OneDGoTest, EdgeBoardNoCapture)
{
    std::string board = ".BBBW";
    EXPECT_EQ(solve_1d_go(board), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}