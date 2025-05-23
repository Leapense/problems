#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    long long a, b;
    cin >> a >> b;

    long long result = 0;

    while (a != 0 && b != 0) {
        if (a > b) swap(a, b);

        result += b / a;
        b = b % a;
    }

    cout << result << '\n';

    return 0;
}