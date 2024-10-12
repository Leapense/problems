#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull n, a;

    cin >> n >> a;

    ull a_min = a;
    ull a_max = a;

    for (ull k = 1; k <= n; ++k) {
        ull mask = 1ULL << (k - 1);
        ull b = a ^ mask;
        a_min = min(a_min, b);
        a_max = max(a_max, b);
    }

    cout << a_min << " " << a_max << "\n";

    return 0;
}