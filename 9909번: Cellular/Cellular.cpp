#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, g;
    cin >> n >> g;
    vector<vector<int>> start(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            start[i][j] = s[j] - '0';
        }
    }
    string dummy;
    getline(cin, dummy);
    vector<vector<int>> target(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            target[i][j] = s[j] - '0';
        }
    }
    for (int rule = 0; rule < 64; rule++)
    {
        vector<vector<int>> curr = start;
        for (int gen = 0; gen < g; gen++)
        {
            vector<vector<int>> next(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int sum = curr[i][j];
                    if (i > 0)
                        sum += curr[i - 1][j];
                    if (i < n - 1)
                        sum += curr[i + 1][j];
                    if (j > 0)
                        sum += curr[i][j - 1];
                    if (j < n - 1)
                        sum += curr[i][j + 1];
                    int newState = (rule >> sum) & 1;
                    next[i][j] = newState;
                }
            }
            curr = next;
        }
        if (curr == target)
        {
            cout << rule;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
