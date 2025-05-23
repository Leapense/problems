#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> sums(n);

    for (long long i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        sums[i] = x + y;
    }

    sort(sums.begin(), sums.end());

    long long unique_count = n > 0 ? 1 : 0;
    for (long long i = 1; i < n; ++i) {
        if (sums[i] != sums[i - 1]) {
            unique_count++;
        }
    }

    cout << unique_count << "\n";

    return 0;
}