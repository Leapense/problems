#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

void solve(istream &in, ostream &out) {
    int N, M, R;
    in >> N >> M >> R;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].rbegin(), adj[i].rend());
    }

    vector<int> depth(N + 1, -1);
    vector<int> order(N + 1, 0);

    vector<int> index(N + 1, 0);
    stack<int> s;

    int counter = 1;
    depth[R] = 0;
    order[R] = counter;
    s.push(R);

    while (!s.empty()) {
        int v = s.top();
        if (index[v] < adj[v].size()) {
            int w = adj[v][index[v]++];
            if (order[w] == 0) {
                depth[w] = depth[v] + 1;
                order[w] = ++counter;
                s.push(w);
            }
        } else {
            s.pop();
        }
    }
    
    long long result = 0;
    for (int i = 1; i <= N; i++) {
        result += (long long) depth[i] * order[i];
    }

    out << result;
}

TEST(DFSTest, SampleTest1) {
    string input = "5 5 1\n"
                   "1 4\n"
                   "1 2\n"
                   "2 3\n"
                   "2 4\n"
                   "3 4\n";
    string expected_output = "20";

    istringstream iss(input);
    ostringstream oss;

    solve(iss, oss);
    EXPECT_EQ(oss.str(), expected_output);
}

TEST(DFSTest, DisconnectedGraph) {
    string input = "6 3 1\n"
                   "1 2\n"
                   "2 3\n"
                   "4 5\n";

    string expected_output = "8";

    istringstream iss(input);
    ostringstream oss;

    solve(iss, oss);
    EXPECT_EQ(oss.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
