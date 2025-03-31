#include <gtest/gtest.h>
#include "../cpp/src/main.h"
#include <string>

TEST(ForestForTheTrees, Sample1) {
    std::string input = "2 6\n1 1 5 4\n";
    std::string expected = "Yes";
    EXPECT_EQ(solve_problem(input), expected);
}

TEST(ForestForTheTrees, Sample2) {
    std::string input = "2 6\n3 5 5 7\n";
    std::string expected = "No\n1 3";
    EXPECT_EQ(solve_problem(input), expected);
}

TEST(ForestForTheTrees, Sample3) {
    std::string input = "830844890448 39710592053\n821266 42860 402207107926 423171345006\n";
    std::string expected = "No\n402207964848 19223704203";
    EXPECT_EQ(solve_problem(input), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
