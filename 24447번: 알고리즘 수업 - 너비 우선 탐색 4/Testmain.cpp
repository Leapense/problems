#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

void solve(istream& in, ostream& out) {
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
    vector<int> depth(N + 1, -1);

    queue<int> q;
    order[R] = 1;
    depth[R] = 0;
    q.push(R);

    int visitCounter = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (order[v] == 0) {
                order[v] = ++visitCounter;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        answer += static_cast<long long>(depth[i]) * order[i];
    }

    out << answer << "\n";
}

TEST(BFSTest, SampleTest) {
    stringstream input;
    input << "5 5 1\n";
    input << "1 4\n";
    input << "1 2\n";
    input << "2 3\n";
    input << "2 4\n";
    input << "3 4\n";

    stringstream output;
    solve(input, output);

    EXPECT_EQ(output.str(), "13\n");
}

#ifndef UNIT_TEST
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif
