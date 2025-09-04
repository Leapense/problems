#include <bits/stdc++.h>
using namespace std;

int n;
long long target;
vector<long long> coeffv;
vector<int> answer;
bitset<16> used;

vector<long long> build_binom_row(int k) {
    vector<long long> c(k + 1);
    c[0] = 1;
    for (int i = 1; i <= k; ++i) {
        c[i] = 1;
        for (int j = i - 1; j >= 1; --j) c[j] = c[j] + c[j - 1];
    }
    return c;
}

bool feasible_range(int idx, long long s) {
    vector<long long> remC;
    for (int i = idx + 1; i < n; ++i) remC.push_back(coeffv[i]);
    ranges::sort(remC, ranges::greater{});
    vector<int> avail;
    for (int v = 1; v <= n; ++v) if (!used[v]) avail.push_back(v);
    vector<int> asc = avail, desc = avail;
    ranges::sort(asc);
    ranges::sort(desc, ranges::greater{});
    long long minAdd = 0, maxAdd = 0;
    for (size_t i = 0; i < remC.size(); ++i) {
        minAdd += 1LL * asc[i] * remC[i];
        maxAdd += 1LL * desc[i] * remC[i];
    }

    return s + minAdd <= target && target <= s + maxAdd;
}

bool dfs(int idx, long long s) {
    if (idx == n) return s == target;
    for (int v = 1; v <= n; ++v) {
        if (used[v]) continue;
        long long ns = s + 1LL * v * coeffv[idx];
        used[v] = true;
        if (feasible_range(idx, ns)) {
            answer[idx] = v;
            if (dfs(idx + 1, ns)) return true;
        }

        used[v] = false;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n >> target)) return 0;
    auto row = build_binom_row(n - 1);
    coeffv.assign(row.begin(), row.end());
    answer.assign(n, 0);
    used.reset();
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}