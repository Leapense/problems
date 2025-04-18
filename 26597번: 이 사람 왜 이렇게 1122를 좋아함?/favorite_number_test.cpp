#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
using int64 = long long;

/**
  * solve(): 준성이의 최애 수 질의응답 결과를 계산
  * @param Q : 질의 개수
  * @param queries: 각 질의의 (x, op) 쌍. op='^'이면 최애 수 > x, op=='v'이면 최애 수 < x
  * @return pair:
  * - first: "Paradox!", "I got it!", "Hmm..."
  * - second: 모순 또는 확정 시점 (1-based). 해당 없으면 -1
  */
pair<string,int> solve(int Q, const vector<pair<int64, char>>& queries) {
    const int64 INF = 1000000000000000000LL;
    int64 L = -INF, R = INF;
    bool paradox = false, gotit = false;
    int paradox_at = -1, gotit_at = -1;

    for (int i = 0; i < Q; i++) {
        auto [x, op] = queries[i];
        if (op == '^') {
            L = max(L, x + 1);
        } else {
            R = min(R, x - 1);
        }

        if (!paradox && L > R) {
            paradox = true;
            paradox_at = i + 1;
        }
        if (!paradox && !gotit && L == R) {
            gotit = true;
            gotit_at = i + 1;
        }
    }

    if (paradox) return {"Paradox!", paradox_at};
    else if (gotit) return {"I got it!", gotit_at};
    else return {"Hmm...", -1};
}

TEST(SampleTests, Example1) {
    vector<pair<int64, char>> q = {{3, '^'}, {6, 'v'}};
    auto res = solve(2, q);
    EXPECT_EQ(res.first, "Hmm...");
    EXPECT_EQ(res.second, -1);
}

TEST(SampleTests, Example2) {
    vector<pair<int64, char>> q = {{3, '^'}, {6, 'v'}, {5, 'v'}, {2, '^'}};
    auto res = solve(4, q);
    EXPECT_EQ(res.first, "I got it!");
    EXPECT_EQ(res.second, 3);
}

TEST(SampleTests, Example3) {
    vector<pair<int64, char>> q = {{7, '^'}, {5, 'v'}, {2, 'v'}};
    auto res = solve(3, q);
    EXPECT_EQ(res.first, "Paradox!");
    EXPECT_EQ(res.second, 2);
}

TEST(EdgeCases, AllUpperBounds) {
    vector<pair<int64, char>> q;
    for (int i = 0; i < 5; i++) {
        q.emplace_back(0 - i, 'v');
    }

    auto res = solve(5, q);
    EXPECT_EQ(res.first, "Hmm...");
    EXPECT_EQ(res.second, -1);
}

TEST(EdgeCases, ImmediateParadox) {
    vector<pair<int64, char>> q = {{1000000000000000000LL, '^'}};
    auto res = solve(1, q);
    EXPECT_EQ(res.first, "Paradox!");
    EXPECT_EQ(res.second, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
