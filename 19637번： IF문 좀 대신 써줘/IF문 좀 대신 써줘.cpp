#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<long long> upper_limits(N);
    vector<string> titles(N);

    for (int i = 0; i < N; ++i) {
        cin >> titles[i] >> upper_limits[i];
    }

    for (int i = 0; i < M; ++i) {
        long long power;
        cin >> power;

        int idx = lower_bound(upper_limits.begin(), upper_limits.end(), power) - upper_limits.begin();

        cout << titles[idx] << "\n";
    }

    return 0;
}