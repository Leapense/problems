#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> c(N + 1);
    for (auto &x : c) cin >> x;

    long long sum_digits = 0;

    int num_terms = 0;

    for (int i = 1; i <= N; i++) if (c[i] > 0) {
        num_terms++;
        sum_digits += floor(log10((double)c[i])) + 1;
    }

    long long K = 1 + 2 * (N - 1) + num_terms + sum_digits + 1;
    cout << K << "\n";

    return 0;
}