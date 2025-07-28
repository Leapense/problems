#include <bits/stdc++.h>
using namespace std;

static auto buildAllowed(int k, int m) {
    array<array<bool, 10>, 10> allow{};
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            allow[i][j] = i != j;
        }
    }
    for (int g = 0; g < m; ++g) {
        string line;
        cin >> line;
        for (size_t i = 0; i < line.size(); ++i) {
            for (size_t j = i + 1; j < line.size(); ++j) {
                int a = line[i] - 'A';
                int b = line[j] - 'A';
                allow[a][b] = false;
                allow[b][a] = false;
            }
        }
    }
    return allow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    if (!(cin >> n >> k >> m)) {
        return 0;
    }
    auto allow = buildAllowed(k, m);
    array<int32_t, 10> prev{}, curr{};
    prev.fill(1);
    for (int pos = 1; pos < n; ++pos) {
        curr.fill(0);
        for (int pr = 0; pr < k; ++pr) {
            if (prev[pr] == 0) {
                continue;
            }
            for (int cu = 0; cu < k; ++cu) {
                if (allow[pr][cu]) {
                    curr[cu] += prev[pr];
                }
            }
        }
        prev = curr;
    }
    int32_t total = accumulate(prev.begin(), prev.begin() + k, 0);
    cout << total << '\n';
    return 0;
}