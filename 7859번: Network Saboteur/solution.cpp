#include <bits/stdc++.h>
using namespace std;

static constexpr int MAX_N = 20;
using Matrix = vector<vector<int>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N < 2 || N > MAX_N) {
        return 0;
    }

    Matrix C(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> C[i][j];
        }
    }

    long long maxTraffic = 0;
    int limit = 1 << (N - 1);
    for (int mask = 0; mask < limit; ++mask) {
        long long current = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                bool inA_i = (mask >> i) & 1;
                bool inA_j = (mask >> j) & 1;
                if (inA_i != inA_j) {
                    current += C[i][j];
                }
            }
        }
        maxTraffic = max(maxTraffic, current);
    }

    cout << maxTraffic << "\n";
    return 0;
}