#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> disks(n);
        int blackCount = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> disks[i];
            if (disks[i] == 1)
                blackCount++;
        }
        long long inv = 0;
        for (int i = 0; i < n; i++)
        {
            if (disks[i] == 1)
            {
                if (i % 2 == 0)
                    inv += 1;
                else
                    inv -= 1;
            }
        }
        if (blackCount % 2 == 0)
        {
            if (inv == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            if (abs(inv) == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}