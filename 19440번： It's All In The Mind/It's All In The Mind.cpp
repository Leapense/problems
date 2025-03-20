#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> fixedVals(n + 1, -1);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            fixedVals[x] = y;
        }
        int a1 = fixedVals[1] != -1 ? fixedVals[1] : 100;
        int a2 = fixedVals[2] != -1 ? fixedVals[2] : 100;
        vector<int> L(n + 1, 0);
        for (int i = n; i >= 3; i--)
        {
            if (fixedVals[i] != -1)
            {
                if (i == n)
                    L[i] = fixedVals[i];
                else
                    L[i] = max(fixedVals[i], L[i + 1]);
            }
            else
            {
                if (i == n)
                    L[i] = 0;
                else
                    L[i] = L[i + 1];
            }
        }
        ll sumOthers = 0;
        for (int i = 3; i <= n; i++)
            sumOthers += L[i];
        ll num = a1 + a2;
        ll den = num + sumOthers;
        ll g = gcd(num, den);
        num /= g;
        den /= g;
        cout << num << "/" << den << "\n";
    }
    return 0;
}