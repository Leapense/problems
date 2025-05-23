#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, l, k, s;
    cin >> m >> l >> k >> s;

    vector<int> c(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
    }

    vector<long long> total_reserved(m + 1, 0);
    for (int i = 0; i < l; ++i) {
        int p, r;
        cin >> p >> r;
        total_reserved[p] += r;
    }

    long long total_profit = 0;
    for (int i = 1; i <= m; ++i) {
        long long total_tickets = total_reserved[i];
        long long N = total_tickets / k;
        long long t_remaining = total_tickets % k;
        long long profit = c[i] * N * k - s * N;

        long long delta_profit = c[i] * t_remaining - s;
        if (delta_profit >= 0) {
            profit += delta_profit;
        } else {
            long long t_extra = (s + c[i] - 1) / c[i];
            if (t_extra <= t_remaining) {
                profit += c[i] * t_extra - s;
            }
        }
        total_profit += profit;
    }

    cout << total_profit << endl;
    return 0;
}