#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <optional>

// 테스트 케이스 1: Sample Input 1
TEST(OthelloTest, SampleTest1)
{
    std::vector<std::string> board = {
        ".B.",
        ".W.",
        "..."};
    auto move = find_best_move(board);
    ASSERT_TRUE(move.has_value());
    EXPECT_EQ(move->x, 1);
    EXPECT_EQ(move->y, 2);
    EXPECT_EQ(move->flipCount, 1);
}

// 테스트 케이스 2: Sample Input 2
TEST(OthelloTest, SampleTest2)
{
    std::vector<std::string> board = {
        ".WWWB",
        "BWWBB",
        "WBWBB",
        "WBBWB",
        "W...B"};
    auto move = find_best_move(board);
    ASSERT_TRUE(move.has_value());
    EXPECT_EQ(move->x, 0);
    EXPECT_EQ(move->y, 0);
    EXPECT_EQ(move->flipCount, 6);
}

// 테스트 케이스 3: Sample Input 3 (유효한 이동 없음)
TEST(OthelloTest, SampleTest3)
{
    std::vector<std::string> board = {
        ".WWWWWW.",
        "WWWWWWWW",
        "WWWWWWWW",
        "WWBWWWWW",
        "WWWWWWWW",
        "WWWWWWWW",
        "WWWWWWWW",
        ".WWWWWW."};
    auto move = find_best_move(board);
    EXPECT_FALSE(move.has_value());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}