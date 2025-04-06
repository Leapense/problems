#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <string>
#include "gtest/gtest.h"

using namespace std;

void solve(istream& in, ostream& out) {
    int N, M, R;
    in >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        in >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        sort(graph[i].rbegin(), graph[i].rend());
    }

    vector<int> depth(N + 1, -1);


    stack<pair<int, int>> st;
    st.push({R, 0});

    while (!st.empty()) {
        auto [cur, d] = st.top();
        st.pop();
        if (depth[cur] != -1) continue;
        depth[cur] = d;

        for (auto it = graph[cur].rbegin(); it != graph[cur].rend(); ++it) {
            if (depth[*it] == -1) {
                st.push({*it, d + 1});
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        out << depth[i] << "\n";
    }
}

TEST(DFSTest, SampleTest1) {
    string input = "5 5 1\n1 4\n1 2\n2 3\n2 4\n3 4\n";
    string expected_output = "0\n3\n2\n1\n-1\n";

    stringstream ss_input(input), ss_output;
    solve(ss_input, ss_output);

    EXPECT_EQ(ss_output.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
