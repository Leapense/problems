#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

pair<int, int> maxChocolates(vector<int> choco, int K) {
    int N = choco.size();
    int total_eaten = 0;
    int days = 0;

    while (true) {
        int max_eat = 0;
        int selected_idx = -1;

        for (int i = K; i < N; ++i) {
            int eat = choco[i] - choco[i - K];
            if (eat > max_eat) {
                max_eat = eat;
                selected_idx = i;
            }
        }

        if (selected_idx == -1) break;

        choco[selected_idx] -= max_eat;
        total_eaten += max_eat;
        ++days;

        sort(choco.begin(), choco.end());
    }

    return {total_eaten, days};
}

// 테스트 코드
TEST(ChocolateTest, Sample1) {
    vector<int> choco = {1, 2, 2, 3};
    int K = 2;
    auto [eaten, days] = maxChocolates(choco, K);
    EXPECT_EQ(eaten, 4);
    EXPECT_EQ(days, 3);
}

TEST(ChocolateTest, Sample2) {
    vector<int> choco = {5, 5};
    int K = 1;
    auto [eaten, days] = maxChocolates(choco, K);
    EXPECT_EQ(eaten, 0);
    EXPECT_EQ(days, 0);
}

TEST(ChocolateTest, NoReductionNeeded) {
    vector<int> choco = {1, 1, 1, 1};
    int K = 2;
    auto [eaten, days] = maxChocolates(choco, K);
    EXPECT_EQ(eaten, 0);
    EXPECT_EQ(days, 0);
}

TEST(ChocolateTest, MaxEaten) {
    vector<int> choco = {1, 2, 3, 4, 5, 6};
    int K = 3;
    auto [eaten, days] = maxChocolates(choco, K);
    EXPECT_GT(eaten, 0);
    EXPECT_GT(days, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
