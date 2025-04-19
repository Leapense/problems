#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> split_sum(long long n)
{
    long long x = 0, y = 0, place = 1;
    bool toggle = false;
    while (n)
    {
        int d = n % 10;
        int a = d / 2, b = d / 2;
        if (d & 1)
        {
            if (toggle)
                ++b;
            else
                ++a;
            toggle = !toggle;
        }
        x += 1LL * a * place;
        y += 1LL * b * place;
        place *= 10;
        n /= 10;
    }
    return {x, y};
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        auto [x, y] = split_sum(n);
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
#endif