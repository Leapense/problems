#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n, s;
    cin >> n >> s;

    vector<int> d(n);

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    long long LCM = d[0];

    for (int i = 1; i < n; ++i) {
        LCM = lcm(LCM, d[i]);
    }

    int dayOfWeek = (s - 1 + LCM) % 7 + 1;
    cout << dayOfWeek << '\n';

    return 0;
}