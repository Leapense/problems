#include <bits/stdc++.h>
using namespace std;

long long find_min_X(int N) {
    if (N == 1) return 1;
    vector<bool> visited(N, false);
    queue<pair<long long, int>> q;
    q.push({1, 1 % N});
    visited[1 % N] = true;
    while (!q.empty()) {
        auto [X, r] = q.front(); q.pop();
        if (r == 0) {
            return X;
        }

        long long new_X0 = X * 10;
        int new_r0 = (r * 10) % N;
        if (!visited[new_r0]) {
            q.push({new_X0, new_r0});
            visited[new_r0] = true;
        }

        long long new_X1 = X * 10 + 1;
        int new_r1 = (r * 10 + 1) % N;
        if(!visited[new_r1]){
            q.push({new_X1, new_r1});
            visited[new_r1] = true;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        long long result = find_min_X(N);
        cout << result << "\n";
    }

    return 0;
}