#include <bits/stdc++.h>
using namespace std;

static constexpr long long MOD = 1'000'000LL;

long long countWays(long long n) {
    long long m = n / 3;
    long long total = m + 1;
    long long p = n & 1;

    long long C1 = (p == 0) ? (total >> 1) : (m / 2 + 1);

    long long part1 = total * n;
    long long part2 = 3LL * m * total / 2;
    long long numerator = part1 - part2 - C1;
    long long answer = numerator / 2 + total;

    return answer % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        cout << countWays(n) << "\n";
    }

    return 0;
}