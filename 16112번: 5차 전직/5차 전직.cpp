#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), greater<long long>());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = min(n - 1 - i, k);
        ans += a[i] * cnt;
    }

    cout << ans << "\n";

    return 0;
}