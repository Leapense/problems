#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<int> res(n + m - 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = 0; j < m; j++)
        {
            if (b[j] == 0)
                continue;
            res[i + j] ^= 1;
        }
    }

    return res;
}

vector<int> modPoly(vector<int> dividend, const vector<int> &divisor)
{
    int degDivisor = divisor.size() - 1;
    int degDividend = dividend.size() - 1;
    while (degDividend >= degDivisor)
    {
        if (dividend[degDividend] == 1)
        {
            for (int i = 0; i <= degDivisor; i++)
            {
                dividend[degDividend - degDivisor + i] ^= divisor[i];
            }
        }
        degDividend--;
    }

    while (dividend.size() > 1 && dividend.back() == 0)
        dividend.pop_back();
    return dividend;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int lenf;
        cin >> lenf;
        vector<int> f(lenf);
        for (int i = 0; i < lenf; i++)
            cin >> f[i];
        int leng;
        cin >> leng;
        vector<int> g(leng);
        for (int i = 0; i < leng; i++)
            cin >> g[i];
        int lenh;
        cin >> lenh;
        vector<int> h(lenh);
        for (int i = 0; i < lenh; i++)
            cin >> h[i];

        vector<int> f_rev(f.rbegin(), f.rend());
        vector<int> g_rev(g.rbegin(), g.rend());
        vector<int> h_rev(h.rbegin(), h.rend());

        vector<int> prod = multiply(f_rev, g_rev);
        vector<int> rem = modPoly(prod, h_rev);

        vector<int> rem_out(rem.rbegin(), rem.rend());
        cout << rem_out.size();
        for (int bit : rem_out)
            cout << " " << bit;
        cout << "\n";
    }

    return 0;
}