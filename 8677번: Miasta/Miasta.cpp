#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> d(n - 1);
    for (auto &x : d)
        cin >> x;
    vector<int> right_reach(n + 1);
    for (int i = 1; i <= n; i++)
        right_reach[i] = i;
    for (int i = n - 1; i >= 1; i--)
    {
        if (d[i - 1] == 0 || d[i - 1] == 2)
        {
            right_reach[i] = right_reach[i + 1];
        }
    }
    vector<int> left_reach(n + 1);
    for (int i = 1; i <= n; i++)
        left_reach[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (d[i - 2] == 1 || d[i - 2] == 2)
        {
            left_reach[i] = left_reach[i - 1];
        }
    }
    vector<int> w(n);
    for (int i = 1; i <= n; i++)
    {
        w[i - 1] = (right_reach[i] - i) + (i - left_reach[i]);
    }
    for (int i = 0; i < n; i++)
        cout << w[i] << (i < n - 1 ? " " : "\n");

    return 0;
}