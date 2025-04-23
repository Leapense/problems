#include <bits/stdc++.h>

using namespace std;

void solve(istream &cin, ostream &cout)
{
    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<bool>> covered(n, vector<bool>(m, false));
    int dx1[5] = {0, -1, -1, 1, 1}, dy1[5] = {0, -1, 1, -1, 1};
    int dx2[4] = {-1, 0, 0, 1}, dy2[4] = {0, -1, 1, 0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            bool ok = true;
            for (int k = 0; k < 5; k++)
            {
                int ni = i + dx1[k], nj = j + dy1[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                {
                    if (a[ni][nj] != '*')
                    {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok)
                for (int k = 0; k < 5; k++)
                {
                    int ni = i + dx1[k], nj = j + dy1[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                        covered[ni][nj] = true;
                }

            ok = true;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + dx2[k], nj = j + dy2[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                {
                    if (a[ni][nj] != '*')
                    {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok)
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + dx2[k], nj = j + dy2[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                        covered[ni][nj] = true;
                }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if ((a[i][j] == '*') != covered[i][j])
            {
                cout << "NO";
                return;
            }
        }

    cout << "YES";
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif