#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    vector<bool> bad(n, false);

    for (int i = 1; i <= n; ++i)
    {
        int k;
        if (a[i] <= i)
        {
            k = i - a[i];
        }
        else
        {
            k = n + i - a[i];
        }

        if (k >= 0 && k < n)
        {
            bad[k] = true;
        }
    }

    for (int k = 0; k < n; ++k)
    {
        if (!bad[k])
        {
            cout << k << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}