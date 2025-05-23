#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> S(N);
    for (auto &x : S) cin >> x;

    vector<int> D(N);
    for (auto &x : D) {
        cin >> x;
        x--;
    }

    vector<int> Dk(N, 0);
    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                cycle.push_back(j);
                j = D[j];
            }
            int L = cycle.size();
            for (int idx = 0; idx < L; idx++) {
                Dk[cycle[idx]] = cycle[(idx + K) % L];
            }
        }
    }

    vector<int> invDk(N, 0);
    for (int i = 0; i < N; i++) invDk[Dk[i]] = i;
    vector<int> P(N);
    for (int i = 0; i < N; i++) P[i] = S[invDk[i]];
    for (int i = 0; i < N; i++) cout << P[i] << (i < N - 1 ? " " : "\n");

    return 0;
}