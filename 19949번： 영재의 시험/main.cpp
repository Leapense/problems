#include <iostream>
#include <vector>
#include <array>
#include <cstring>
using namespace std;

constexpr int MAX_POS = 11;
constexpr int MAX_LAST = 6;
constexpr int MAX_COUNT = 3;
constexpr int MAX_SCORE = 11;

long long dp[MAX_POS][MAX_LAST][MAX_COUNT][MAX_SCORE];
bool visited[MAX_POS][MAX_LAST][MAX_COUNT][MAX_SCORE];

long long solve_dp(int pos, int last, int count, int score, const vector<int> &correct)
{
    if (pos == 10)
    {
        return (score >= 5) ? 1 : 0;
    }
    if (visited[pos][last][count][score])
    {
        return dp[pos][last][count][score];
    }

    visited[pos][last][count][score] = true;
    long long ways = 0;
    for (int candidate = 1; candidate <= 5; candidate++)
    {
        int newCount = (last == candidate) ? count + 1 : 1;

        if (newCount == 3)
            continue;

        int newScore = score + (candidate == correct[pos] ? 1 : 0);

        ways += solve_dp(pos + 1, candidate, newCount, newScore, correct);
    }

    dp[pos][last][count][score] = ways;
    return ways;
}

#ifndef UNIT_TESTS
int main()
{
    vector<int> correct(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> correct[i];
    }

    memset(visited, 0, sizeof(visited));

    long long result = solve_dp(0, 0, 0, 0, correct);
    cout << result << endl;
    return 0;
}
#endif
#ifdef UNIT_TESTS
#include <gtest/gtest.h>

long long computeAnswer(const vector<int> &correct)
{
    memset(visited, 0, sizeof(visited));
    return solve_dp(0, 0, 0, 0, correct);
}

TEST(ExamTest, SampleTest)
{
    vector<int> correct = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    EXPECT_EQ(computeAnswer(correct), 261622);
}

TEST(ExamTest, AllSameAnswers)
{
    vector<int> correct(10, 1);
    long long result = computeAnswer(correct);
    EXPECT_GT(result, 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif