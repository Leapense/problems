#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cur;

void dfs(int start, int sum) {
    if (sum == n) {
        if (!cur.empty()) {
            for (size_t i = 0; i < cur.size(); ++i) {
                if (i) cout << '+';
                cout << cur[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int x = start; x <= n; ++x) {
        if (sum + x > n) break;
        if (cur.size() >= 2) {
            int a = cur[cur.size() - 2];
            int b = cur.back();
            if (2 * b == a + x) continue;
        }
        cur.push_back(x);
        dfs(x + 1, sum + x);
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    dfs(1, 0);
    return 0;
}