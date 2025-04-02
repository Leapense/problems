#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(MakePurseLightTest, SampleTest1) {
    int price = 160;
    std::vector<int> coins = {1, 1, 2, 0};
    auto res = solveCase(price, coins);

    std::vector<std::pair<int, int>> expected = {{10, 1}, {50, 1}, {100, 1}};
    EXPECT_EQ(res, expected);
}

TEST(MakePurseLightTest, SampleTest2) {
    int price = 160;
    std::vector<int> coins = {1, 0, 2, 10};
    auto res = solveCase(price, coins);

    std::vector<std::pair<int, int>> expected = {{10, 1}, {100, 2}};
    EXPECT_EQ(res, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
