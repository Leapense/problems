#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adjacency;
vector<int> orderList;
vector<int> result;

bool foundFlag = false;

void backtrack(int index) {
    if (foundFlag) return;
    if (index == N) {
        for (int i = 1; i <= N; ++i) {
            cout << result[i];
        }
        cout << "\n";
        foundFlag = true;
        return;
    }

    int pasture = orderList[index];
    for (int color = 1; color <= 4; ++color) {

        bool conflict = false;
        for (auto &neighbor : adjacency[pasture]) {
            if (result[neighbor] == color) {
                conflict = true;
                break;
            }
        }
        if (!conflict) {
            result[pasture] = color;
            backtrack(index + 1);
            result[pasture] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adjacency.assign(N + 1, vector<int>());

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }

    orderList.resize(N);
    for (int i = 0; i < N; ++i) {
        orderList[i] = i + 1;
    }

    sort(orderList.begin(), orderList.end(), [&](const int &a, const int &b) -> bool {
        return adjacency[a].size() > adjacency[b].size();
    });

    result.assign(N + 1, 0);
    backtrack(0);

    return 0;
}