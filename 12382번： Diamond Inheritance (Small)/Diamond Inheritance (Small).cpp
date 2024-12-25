#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool hasDiamondInheritance(int N, vector<vector<int>>& graph) {
    for (int i = 1; i <= N; ++i) {
        vector<set<int>> paths(N + 1);
        vector<int> stack;
        stack.push_back(i);

        while (!stack.empty()) {
            int current = stack.back();
            stack.pop_back();
            
            for (int parent : graph[current]) {
                if (paths[parent].empty()) {
                    paths[parent].insert(current);
                    stack.push_back(parent);
                } else {
                    if (paths[parent].size() >= 1) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        vector<vector<int>> graph(N + 1);

        for (int i = 1; i <= N; ++i) {
            int M;
            cin >> M;
            for (int j = 0; j < M; ++j) {
                int parent;
                cin >> parent;

                graph[i].push_back(parent);
            }
        }

        if (hasDiamondInheritance(N, graph)) {
            cout << "Case #" << t << ": Yes" << endl;
        } else {
            cout << "Case #" << t << ": No" << endl;
        }
    }

    return 0;
}