#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    vector<long long> prefix_max(n, 0);
    prefix_max[0] = w[0];
    for (int i = 1; i < n; i++) {
        prefix_max[i] = max(prefix_max[i - 1], w[i]);
    }

    vector<long long> suffix_max(n, 0);
    suffix_max[n - 1] = w[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix_max[i] = max(suffix_max[i + 1], w[i]);
    }

    for (int i = 0; i < n; i++) {
        long long a_i, b_i;

        if (i == 0) {
            a_i = w[i];
        } else {
            if (prefix_max[i - 1] > w[i]) a_i = prefix_max[i - 1];
            else a_i = w[i];
        }

        if (i == n - 1) {
            b_i = w[i];
        } else {
            if (suffix_max[i + 1] > w[i]) b_i = suffix_max[i + 1];
            else b_i = w[i];
        }

        printf("%lld %lld\n", a_i, b_i);
    }

    return 0;
}