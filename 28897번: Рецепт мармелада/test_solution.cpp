// recipe_test.cpp
#include <gtest/gtest.h>
#include <sstream>
#include "solution.cpp"

TEST(RecipeTest, Sample1) {
    std::istringstream in("3 2\n1 3\n");
    EXPECT_EQ(solve(in), "1 2 2");
}

TEST(RecipeTest, Sample2) {
    std::istringstream in("5 6\n1 2 3 4 5 5\n");
    EXPECT_EQ(solve(in), "1 2 3 4 5");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
