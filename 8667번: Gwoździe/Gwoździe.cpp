#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long k;

    cin >> n >> k;

    vector<long long> w(n);

    for (auto &x : w) cin >> x;

    sort(w.begin(), w.end());

    vector<pair<long long, int>> freq;

    freq.emplace_back(w[0], 1);

    for (int i = 1; i < n; i++) {
        if (w[i] == freq.back().first) freq.back().second++;
        else freq.emplace_back(w[i], 1);
    }

    int m = freq.size();
    vector<long long> suffix(m, 0);
    suffix[m - 1] = 0;

    for (int i = m - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + freq[i + 1].second;
    }

    long long res = 0;

    for (int i = 0; i < m; i++) {
        long long current = freq[i].second + min((long long)suffix[i], k);
        res = max(res, current);
    }

    cout << res;

    return 0;
}