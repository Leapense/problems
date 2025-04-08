#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<int> girls(n), boys(m);
    for (int &x : girls)
        cin >> x;
    for (int &x : boys)
        cin >> x;

    sort(girls.begin(), girls.end());
    sort(boys.begin(), boys.end());

    long long result = 0;

    for (int h : girls)
    {
        auto low = lower_bound(boys.begin(), boys.end(), h - k);
        auto high = upper_bound(boys.begin(), boys.end(), h + k);
        result += high - low;
    }

    cout << result << "\n";
    return 0;
}