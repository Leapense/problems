#include <bits/stdc++.h>
using namespace std;

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N))
        return 0;
    long long a1, a2;

    cin >> a1;
    if (N == 2)
    {
        cin >> a2;
        for (int i = 3; i <= N; ++i)
        {
            long long tmp;
            cin >> tmp;
        }
        cout << (a1 <= a2 ? "YES\n" : "NO\n");
    }
    else
    {
        for (int i = 2; i <= N; ++i)
        {
            long long tmp;
            cin >> tmp;
        }

        cout << "YES\n";
    }

    return 0;
}
#endif