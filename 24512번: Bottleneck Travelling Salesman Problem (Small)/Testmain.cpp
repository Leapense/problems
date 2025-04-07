#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

static const int INF = 5000001;

string solveBTSP(const string &input) {
    stringstream in(input);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    in >> N >> M;

    vector<vector<int>> cost(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < M; i++) {
        int u, v, c;
        in >> u >> v >> c;
        cost[u][v] = c;
    }

    int bestCost = INF;
    vector<int> bestPath;
    vector<bool> visited(N + 1, false);
    vector<int> currentPath;

    function<void(int, int, int, int)> dfs = [&](int count, int currentNode, int maxEdgeSoFar, int startNode) {
        if (count == N) {
            if (cost[currentNode][startNode] == -1) return;
            int finalMaxEdge = max(maxEdgeSoFar, cost[currentNode][startNode]);
            if (finalMaxEdge < bestCost) {
                bestCost = finalMaxEdge;
                bestPath = currentPath;
            }
            return;
        }

        for (int next = 1; next <= N; next++) {
            if (visited[next]) continue;
            if (cost[currentNode][next] == -1) continue;

            int nextMax = max(maxEdgeSoFar, cost[currentNode][next]);
            if (nextMax >= bestCost) continue;

            visited[next] = true;
            currentPath.push_back(next);

            dfs(count + 1, next, nextMax, startNode);

            visited[next] = false;
            currentPath.pop_back();
        }
    };

    for (int startNode = 1; startNode <= 1; startNode++) {
        visited.assign(N + 1, false);
        visited[startNode] = true;
        currentPath.clear();
        currentPath.push_back(startNode);

        dfs(1, startNode, 0, startNode);
    }

    ostringstream out;

    if (bestCost == INF) {
        out << -1 << "\n";
    } else {
        out << bestCost << "\n";
        for (int i = 0; i < (int)bestPath.size(); i++) {
            out << bestPath[i];
            if (i < (int)bestPath.size() - 1) out << " ";
        }

        out << "\n";
    }

    return out.str();
}

static const char* sampleInput1 = R"(3 6
1 2 4
2 3 4
3 1 4
1 3 2
3 2 3
2 1 5
)";
static const char* sampleOutput1 = R"(4
1 2 3
)";

static const char* sampleInput2 = R"(2 1
1 2 3
)";
static const char* sampleOutput2 = R"(-1
)";

TEST(BTSPTest, SampleTest1) {
    string result = solveBTSP(sampleInput1);
    EXPECT_EQ(result, string(sampleOutput1));
}

TEST(BTSPTest, SampleTest2) {
    string result = solveBTSP(sampleInput2);
    EXPECT_EQ(result, string(sampleOutput2));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
