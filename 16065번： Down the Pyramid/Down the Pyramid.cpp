#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), f(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        f[i + 1] = a[i] - f[i];
    }

    long long lower = 0;
    long long upper = 1LL << 60;
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            long long temp = -f[i];
            if (temp > lower)
                lower = temp;
        }
        else
        {
            if (f[i] < upper)
                upper = f[i];
        }
    }

    long long ans = (upper >= lower ? upper - lower + 1 : 0);

    cout << ans << "\n";

    return 0;
}