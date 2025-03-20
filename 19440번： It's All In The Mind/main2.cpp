#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void solve()
{
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
}
#ifdef DEBUG
void runTests()
{
    vector<pair<string, string>> tests = {
        {"6\n2 0\n3 1\n3 1\n5 2\n2 90\n4 50\n4 4\n1 100\n2 80\n3 80\n4 10\n6 3\n1 90\n4 30\n6 0\n2 2\n1 50\n2 20\n", "1/1\n200/201\n19/29\n2/3\n3/4\n1/1\n"}};
    for (auto &test : tests)
    {
        stringstream input(test.first), output;
        streambuf *cinbuf = cin.rdbuf(), *coutbuf = cout.rdbuf();
        cin.rdbuf(input.rdbuf());
        cout.rdbuf(output.rdbuf());
        solve();
        cout.rdbuf(coutbuf);
        cin.rdbuf(cinbuf);
        if (output.str() == test.second)
            cerr << "Test passed\n";
        else
        {
            cerr << "Test failed\nExpected:\n"
                 << test.second << "Got:\n"
                 << output.str();
        }
    }
}
#endif
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    runTests();
#else
    solve();
#endif
    return 0;
}
