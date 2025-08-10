#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<char> visited(N, 0);
    deque<int> q;
    visited[0] = 1;
    q.push_back(0);

    while(!q.empty()) {
        int i = q.front(); q.pop_front();
        if (i == N - 1) {
            cout << "YES\n";
            return 0;
        }

        int maxJ = min(N - 1, i + K);
        for (int j = i + 1; j <= maxJ; ++j) {
            if (visited[j]) continue;
            int diff = A[i] - A[j];
            if (diff < 0) diff = -diff;
            int step = j - i;
            int cost = step * (1 + diff);
            if (cost <= K) {
                visited[j] = 1;
                q.push_back(j);
            }
        }
    }

    cout << "NO\n";
    return 0;
}