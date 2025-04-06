#include <algorithm>
#include <stack>
#include <vector>
#include <utility>
#include <gtest/gtest.h>

using namespace std;

vector<int> runDFS(int N, int R, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(N + 1);
    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) 
    {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> depth(N + 1, -1);

    stack<pair<int, int>> s;
    s.push({R, 0});

    while (!s.empty()) {
        auto [cur, d] = s.top();
        s.pop();

        if (depth[cur] != -1) continue;

        depth[cur] = d;

        for (auto it = graph[cur].rbegin(); it != graph[cur].rend(); ++it) {
            int next = *it;
            if (depth[next] == -1) {
                s.push({next, d + 1});
            }
        }
    }

    return depth;
}

TEST(DFSTest, SampleTestCase) {
    int N = 5, R = 1;
    vector<pair<int, int>> edges = {
        {1, 4},
        {1, 2},
        {2, 3},
        {2, 4},
        {3, 4}
    };

    vector<int> expected = {-1, 0, 1, 2, 3, -1};
    vector<int> result = runDFS(N, R, edges);

    for (int i = 1; i <= N; ++i) {
        EXPECT_EQ(result[i], expected[i]) << "정점 " << i << "의 깊이가 올바르지 않습니다.";
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
