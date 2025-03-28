#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

TEST(ModernArtTest, SampleTest1)
{
    std::istringstream input("3\n3\n2\nR 1\nC 1\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "4");
}

TEST(ModernArtTest, SampleTest2)
{
    std::istringstream input("4\n5\n7\nR 3\nC 1\nC 2\nR 2\nR 2\nC 1\nR 4\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "10");
}

TEST(ModernArtTest, NoOperation)
{
    std::istringstream input("5\n5\n0\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "0");
}

TEST(ModernArtTest, AllToggleOdd)
{
    std::istringstream input("2\n2\n4\nR 1\nR 2\nC 1\nC 2\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "4");
}

TEST(ModernArtTest, RepeatedToggleSameRow)
{
    std::istringstream input("3\n3\n3\nR 2\nR 2\nR 2\n");
    std::ostringstream output;
    solve(input, output);
    // R 2 toggled 3 times: odd -> row 2 is gold -> 3 gold cells.
    EXPECT_EQ(output.str(), "3");
}

TEST(ModernArtTest, SingleRow)
{
    std::istringstream input("1\n4\n2\nC 2\nC 4\n");
    std::ostringstream output;
    solve(input, output);
    // Single row: columns 2 and 4 toggled -> 2 gold cells.
    EXPECT_EQ(output.str(), "2");
}

TEST(ModernArtTest, SingleColumn)
{
    std::istringstream input("4\n1\n3\nR 1\nR 3\nR 3\n");
    std::ostringstream output;
    solve(input, output);
    // Single column: row 1 toggled once (gold), row 3 toggled twice (black), others remain black -> 1 gold cell.
    EXPECT_EQ(output.str(), "1");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}