#include <bits/stdc++.h>
using namespace std;

long long count_diagonal_tiles(long long x, long long y)
{
    return x + y - std::gcd(x, y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    if (!(cin >> x >> y))
        return 0;
    cout << count_diagonal_tiles(x, y) << "\n";

    return 0;
}