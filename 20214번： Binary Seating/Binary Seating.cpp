#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (auto &x : t) cin >> x;
    map<int, int> cnt;

    for (auto x : t) {
        cnt[x]++;
    }

    vector<int> unique_t;

    for (auto &[k, v] : cnt) unique_t.push_back(k);
    sort(unique_t.begin(), unique_t.end());

    int m_total = 0;
    int idx = unique_t.size() - 1;

    vector<long double> P(unique_t.size(), 0.0);

    long double res = 0.0;
    long double prob_m = 1.0;

    for (int i = unique_t.size() - 1; i >= 0; i--) {
        P[i] = pow(0.5, m_total);
        m_total += cnt[unique_t[i]];
    }

    for (int i = 0; i < unique_t.size(); i++) {
        long double p = (1.0 - pow(0.5, cnt[unique_t[i]])) * P[i];
        res += unique_t[i] * p;
    }

    printf("%.10Lf\n", res);

    return 0;
}