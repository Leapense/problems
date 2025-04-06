#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
#include <string>
#include <gtest/gtest.h>

using namespace std;

void solve(istream &in, ostream &out) {
    ios::sync_with_stdio(false);
    in.tie(nullptr);
    
    int N, M, R;
    in >> N >> M >> R;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        in >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> order(N + 1, 0);
    int cnt = 1;

    stack<int> s;
    s.push(R);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (order[cur] != 0) {
            continue;
        }
        order[cur] = cnt++;
        for (auto it = graph[cur].rbegin(); it != graph[cur].rend(); it++) {
            if (order[*it] == 0) {
                s.push(*it);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        out << order[i] << "\n";
    }
}

TEST(DFSTest, SampleTest1) {
    string input = R"(5 5 1
1 4
1 2
2 3
2 4
3 4
)";
    string expected_output = "1\n2\n3\n4\n0\n";

    stringstream in(input), out;
    solve(in, out);
    EXPECT_EQ(out.str(), expected_output);
}

#ifndef UNIT_TEST
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
