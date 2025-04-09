#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <gtest/gtest.h>

using namespace std;

void solve(istream &in, ostream &out) {
    int N, K, M;
    in >> N >> K;

    vector<pair<int, int>> closed;
    for (int i = 0; i < K; i++) {
        int a, b;
        in >> a >> b;
        if (a > b) swap(a, b);
        closed.push_back({a, b});
    }

    in >> M;
    vector<pair<int, int>> queries;
    for (int i = 0; i < M; i++) {
        int x, y;
        in >> x >> y;
        if (x > y) swap(x, y);
        queries.push_back({x, y});
    }

    int ans1 = 0;
    vector<bool> used(K, false);

    for (auto &q : queries) {
        bool need = false;
        for (int i = 0; i < K; i++) {
            int a = closed[i].first, b = closed[i].second;
            int L = q.first, R = q.second;
            int L_int = max(L, a);
            int R_int = min(R, b);
            if (L_int < R_int) {
                need = true;
                used[i] = true;
                break;
            }
        }
        if (need) ans1++;
    }

    int ans2 = 0;
    for (int i = 0; i < K; i++) {
        if (used[i]) ans2++;
    }

    vector<bool> openConn(N, true);
    for (auto &seg : closed) {
        int a = seg.first, b = seg.second;
        for (int i = a; i < b; i++) {
            openConn[i] = false;
        }
    }

    int cur = 0, best = 0;
    for (int i = 1; i < N; i++) {
        if (openConn[i]) {
            cur++;
        } else {
            best = max(best, cur);
            cur = 0;
        }
    }

    best = max(best, cur);
    int ans3 = (best == 0 ? 1 : best + 1);
    out << ans1 << "\n" << ans2 << "\n" << ans3;
}

TEST(HZTest, SampleInput1) {
    string input = R"(20
2
18 20
8 11
5
14 10
8 11
6 8
8 18
14 17
)";
    string expected = "3\n1\n8";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

TEST(HZTest, SampleInput2) {
    string input = R"(20
3
16 12
8 2
17 20
2
2 1
9 4
)";
    string expected = "1\n1\n5";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

TEST(HZTest, SampleInput3) {
    string input = R"(12
1
4 8
4
6 8
9 10
6 8
5 8
)";
    string expected = "3\n1\n5";
    stringstream ss(input), so;
    solve(ss, so);
    EXPECT_EQ(so.str(), expected);
}

#ifndef UNIT_TEST
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
int main() {
    solve(cin, cout);
    return 0;
}
#endif
