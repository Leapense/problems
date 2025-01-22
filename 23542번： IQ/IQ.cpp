#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (auto &x : a)
        cin >> x;

    sort(a.begin(), a.end());
    int max_sum = INT32_MIN, min_sum = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int s = a[i] + a[2 * n - 1 - i];
        max_sum = max(max_sum, s);
        min_sum = min(min_sum, s);
    }
    cout << max_sum - min_sum << endl;

    return 0;
}