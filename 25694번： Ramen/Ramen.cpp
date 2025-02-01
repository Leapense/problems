#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    if (N == 1)
    {
        cout << "YES";
        return 0;
    }
    long long s = 0;
    bool ok = true;
    for (int k = 1; k < N; k++)
    {
        s += a[k - 1];
        if (s <= 0)
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
