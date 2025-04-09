#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <algorithm>

int solve(int N, int K, const std::vector<std::tuple<int,int,int>>& ages) {
    struct Person {
        int age_days;
        int pos;
    };

    std::vector<Person> people(N);

    for (int i = 0; i < N; ++i) {
        auto [G, M, D] = ages[i];
        int total_days = G * 360 + M * 30 + D;
        people[i] = {total_days, i};
    }

    std::vector<int> sorted_ages;
    for (const auto& p : people) {
        sorted_ages.push_back(p.age_days);
    }

    std::sort(sorted_ages.rbegin(), sorted_ages.rend());

    int age_limit = sorted_ages[K - 1];
    int vaccinated = 0, sent_home = 0;

    for (const auto& p : people) {
        if (vaccinated >= K) break;
        if (p.age_days >= age_limit) {
            vaccinated++;
        } else {
            sent_home++;
        }
    }

    return sent_home;
}

TEST(StipeTest, SampleInput1) {
    int N = 3, K = 2;
    std::vector<std::tuple<int,int,int>> ages = {{3,3,3},{2,2,2},{1,1,1}};
    EXPECT_EQ(solve(N, K, ages), 0);
}

TEST(StipeTest, SampleInput2) {
    int N = 3, K = 1;
    std::vector<std::tuple<int,int,int>> ages = {{1,2,3},{2,3,4},{3,4,5}};
    EXPECT_EQ(solve(N, K, ages), 2);
}

TEST(StipeTest, SampleInput3) {
    int N = 4, K = 2;
    std::vector<std::tuple<int,int,int>> ages = {{21,2,0},{21,1,1},{21,2,1},{21,1,0}};
    EXPECT_EQ(solve(N, K, ages), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
