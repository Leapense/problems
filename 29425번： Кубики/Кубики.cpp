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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> prefixMax(n);
    prefixMax[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], a[i]);
    }

    vector<int> suffixMin(n);
    suffixMin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMin[i] = min(suffixMin[i + 1], a[i]);
    }

    vector<int> possible;

    for (int p = 1; p < n; p++)
    {
        if (prefixMax[p - 1] < suffixMin[p])
        {
            possible.push_back(p);
        }
    }

    cout << possible.size() << "\n";

    for (int p : possible)
    {
        cout << p << " ";
    }

    cout << "\n";
    return 0;
}