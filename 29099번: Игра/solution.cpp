#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    long long prev = 0, x;
    long long evenCnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (((x - prev) & 1) == 0)
            ++evenCnt;
        prev = x;
    }
    cout << (evenCnt & 1 ? "First" : "Second") << '\n';
    return 0;
}