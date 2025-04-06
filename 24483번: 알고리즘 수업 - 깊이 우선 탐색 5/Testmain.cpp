#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
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

    vector<int> depth(N + 1, -1);
    vector<int> order(N + 1, 0);
    int cnt = 1;

    struct StackItem {
        int vertex;
        size_t nextIndex;
    };
    stack<StackItem> st;

    depth[R] = 0;
    order[R] = cnt;
    st.push({R, 0});

    while (!st.empty()) {
        auto &top = st.top();
        int cur = top.vertex;
        size_t &idx = top.nextIndex;

        if (idx < graph[cur].size()) {
            int next = graph[cur][idx];
            idx++;
            if (order[next] == 0) {
                cnt++;
                order[next] = cnt;
                depth[next] = depth[cur] + 1;
                st.push({next, 0});
            }
        } else {
            st.pop();
        }
    }

    long long result = 0;
    for (int i = 1; i <= N; i++) {
        result += static_cast<long long> (depth[i]) * order[i];
    }

    out << result << "\n";
}

TEST(DFSTest, SampleTestCase1) {
    string input = R"(5 5 1
1 4
1 2
2 3
2 4
3 4
)";
    string expected = "20\n";
    stringstream ssInput(input);
    stringstream ssOutput;
    solve(ssInput, ssOutput);

    EXPECT_EQ(ssOutput.str(), expected);
}

TEST(DFSTest, DisconnectedGraph) {
    string input = R"(6 4 1
1 2
2 3
4 5
5 6
)";
    string expected = "8\n";
    stringstream ssInput(input);
    stringstream ssOutput;
    solve(ssInput, ssOutput);

    EXPECT_EQ(ssOutput.str(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
