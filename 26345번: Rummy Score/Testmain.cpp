#include <vector>
#include <numeric>
#include <map>
#include <algorithm>
#include <gtest/gtest.h>

namespace RummySolver {

std::map<std::vector<int>, int> memo;

int solve(std::vector<int>& counts) {
    if (memo.count(counts)) {
        return memo[counts];
    }

    int max_grouped_sum = 0;

    for (int i = 1; i <= 13; ++i) {
        if (counts[i] >= 3) {
             for (int k = 3; k <= counts[i]; ++k) {
                int current_group_sum = k * i;
                counts[i] -= k;
                int total_sum_for_this_path = current_group_sum + solve(counts);
                max_grouped_sum = std::max(max_grouped_sum, total_sum_for_this_path);
                counts[i] += k;
             }
        }
    }

    for (int len = 3; len <= 13; ++len) {
        for (int start = 1; start <= 13 - len + 1; ++start) {
            bool possible = true;
            for (int j = 0; j < len; ++j) {
                if (counts[start + j] == 0) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                int current_group_sum = 0;
                for (int j = 0; j < len; ++j) {
                    int card_value = start + j;
                    counts[card_value]--;
                    current_group_sum += card_value;
                }
                int total_sum_for_this_path = current_group_sum + solve(counts);
                max_grouped_sum = std::max(max_grouped_sum, total_sum_for_this_path);

                for (int j = 0; j < len; ++j) {
                    int card_value = start + j;
                    counts[card_value]++;
                }
            }
        }
    }

    return memo[counts] = max_grouped_sum;
}

int calculate_lost_points(const std::vector<int>& hand) {
    std::vector<int> initial_counts(14, 0);
    int total_sum = 0;
    for (int card : hand) {
        initial_counts[card]++;
        total_sum += card;
    }

    memo.clear();
    int max_grouped_value = solve(initial_counts);
    return total_sum - max_grouped_value;
}

} // namespace RummySolver


TEST(RummyScoreTest, Sample1) {
    std::vector<int> hand = {5, 2, 2, 6, 2, 10, 4};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 10);
}

TEST(RummyScoreTest, Sample2) {
    std::vector<int> hand = {11, 11, 11, 11, 1, 2, 3};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 0);
}

TEST(RummyScoreTest, Sample3) {
    std::vector<int> hand = {11, 2, 3, 4, 5, 13, 1};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 24);
}

TEST(RummyScoreTest, Sample4) {
    std::vector<int> hand = {4, 5, 6, 6, 6, 6, 13};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 13);
}

TEST(RummyScoreTest, Sample5) {
    std::vector<int> hand = {2, 2, 2, 3, 4, 8, 10};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 22);
}

TEST(RummyScoreTest, Sample6) {
    std::vector<int> hand = {12, 13, 1, 4, 4, 4, 4};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 26);
}

TEST(RummyScoreTest, Sample7) {
    std::vector<int> hand = {10, 10, 10, 8, 9, 8, 9};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 10);
}

TEST(RummyScoreTest, NoGroupsPossible) {
    std::vector<int> hand = {1, 3, 5, 7, 9, 11, 13};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 49);
}

TEST(RummyScoreTest, FullRun) {
    std::vector<int> hand = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 0);
}

TEST(RummyScoreTest, FullSet) {
    std::vector<int> hand = {7, 7, 7, 7, 7, 7, 7};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 0);
}

TEST(RummyScoreTest, OverlappingPotentialGroups) {
    std::vector<int> hand = {3, 4, 5, 5, 5, 6, 7};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 5);
}

TEST(RummyScoreTest, TwoSeparateGroups) {
    std::vector<int> hand = {1, 1, 1, 10, 11, 12, 5};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 5);
}

TEST(RummyScoreTest, SetAndRunSharingCard) {
     std::vector<int> hand = {4, 4, 4, 5, 6, 9, 9}; // {4,4,4} and {4,5,6} possible
     // Option 1: {4,4,4} (value 12). Remaining {5,6,9,9}. Lost = 5+6+9+9 = 29.
     // Option 2: {4,5,6} (value 15). Remaining {4,4,9,9}. Lost = 4+4+9+9 = 26.
     // Minimal lost points = 26.
     EXPECT_EQ(RummySolver::calculate_lost_points(hand), 26);
}

TEST(RummyScoreTest, FourOfAKindSet) {
    std::vector<int> hand = {8, 8, 8, 8, 1, 3, 5};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 9); // 1+3+5
}

TEST(RummyScoreTest, LongRun) {
    std::vector<int> hand = {2, 3, 4, 5, 6, 10, 12};
    EXPECT_EQ(RummySolver::calculate_lost_points(hand), 22); // 10+12
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}