#include <bits/stdc++.h>
using namespace std;

long long N;
long long k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    vector<long long> prefix_sum(N + 1, 0), prefix_sumsq(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
        prefix_sumsq[i] = prefix_sumsq[i - 1] + A[i] * A[i];
    }

    for (int k = 1; k <= N; k++) {
        long long max_val = -1;
        int best_i = 1;

        for (int i = 1; i + k - 1 <= N; i++) {
            long long sum = prefix_sum[i + k - 1] - prefix_sum[i - 1];
            long long sumsq = prefix_sumsq[i + k - 1] - prefix_sumsq[i - 1];
            long long value = sumsq * k - sum * sum;

            if (value > max_val) {
                max_val = value;
                best_i = i;
            }
        }

        cout << best_i << "\n";
    }


    return 0;

}