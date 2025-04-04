#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cassert>

#ifdef UNIT_TESTS
#include <gtest/gtest.h>
#endif

using namespace std;

constexpr int MAX_SIZE = 50;
long long dp[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
vector<int> pills;
int total;

bool isAllowed(int mealIndex, int pillType) {
    int time = mealIndex % 3;
    if (time == 0 || time == 2) return (pillType == 0 || pillType == 2);
    return (pillType == 1);
}

long long solveDP(int l, int r, int i) {
    if (i == total) return 1;
    if (visited[l][r][i]) return dp[l][r][i];

    long long ways = 0;

    if (l == r) {
        if(isAllowed(i, pills[l])) ways = solveDP(l + 1, r, i + 1);
    } else {
        if (isAllowed(i, pills[l])) ways += solveDP(l + 1, r, i + 1);
        if (isAllowed(i, pills[r])) ways += solveDP(l, r - 1, i + 1);
    }

    dp[l][r][i] = ways;
    visited[l][r][i] = true;
    return ways;
}

long long computeAnswer(int N) {
    total = 3 * N;
    pills.clear();
    pills.resize(total);
    for (int i = 0; i < N; i++) {
        pills[3 * i] = 0;
        pills[3 * i + 1] = 1;
        pills[3 * i + 2] = 2;
    }

    memset(visited, 0, sizeof(visited));
    return solveDP(0, total - 1, 0);
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cout << computeAnswer(N) << "\n";
    return 0;
}
#endif

#ifdef UNIT_TESTS
TEST(DrugTest, Sample1) {
    EXPECT_EQ(computeAnswer(1), 2);
}

TEST(DrugTest, Sample2) {
    EXPECT_EQ(computeAnswer(2), 6);
}

TEST(DrugTest, AdditionalTest) {
    long long result = computeAnswer(3);
    EXPECT_GT(result, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
