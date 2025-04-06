#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

void solve(istream &in, ostream &out) {
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
    queue<int> q;
    int cnt = 1;

    order[R] = cnt++;
    q.push(R);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur]) {
            if (order[next] == 0) {
                order[next] = cnt++;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        out << order[i] << "\n";
    }
}

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(BFSTest, SampleInput1) {
    string input = "5 5 1\n1 4\n1 2\n2 3\n2 4\n3 4\n";
    string expected_output = "1\n2\n4\n3\n0\n";

    stringstream ss(input), os;
    solve(ss, os);
    EXPECT_EQ(os.str(), expected_output);
}

int main(int argc, char **argv) {
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
