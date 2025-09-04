#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, S;
    if (!(cin >> N >> S)) return 0;
    long long minCost = LLONG_MAX / 4;
    __int128 total = 0;
    for (long long i = 0; i < N; ++i) {
        long long C, Y;
        cin >> C >> Y;
        long long produceNow = C;
        long long carryOver = (minCost <= LLONG_MAX / 4) ? minCost + S : produceNow;
        minCost = min(produceNow, carryOver);
        total += (__int128)minCost * (__int128)Y;
    }
    long long out = (long long) total;
    cout << out << '\n';
    return 0;
}