#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    ll low = 1, high = 1LL * *max_element(a.begin(), a.end()) * m, ans = high;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll sum = 0;

        for (auto x : a)
        {
            sum += mid / x;
            if (sum >= m)
                break;
        }

        if (sum >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}