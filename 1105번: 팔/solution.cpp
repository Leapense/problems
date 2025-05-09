#include <bits/stdc++.h>
using namespace std;

int count_eight(string L, string R)
{
    if (L.size() != R.size())
        return 0;
    int cnt = 0;
    for (size_t i = 0; i < L.size(); ++i)
    {
        if (L[i] == R[i])
        {
            if (L[i] == '8')
                ++cnt;
        }
        else
        {
            break;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string L, R;
    if (!(cin >> L >> R))
        return 0;
    cout << count_eight(L, R) << "\n";
    return 0;
}