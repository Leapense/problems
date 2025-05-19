#include <bits/stdc++.h>
using namespace std;

static int solve(const string &s)
{
    int best = 0;
    char prev = 0;
    int cnt = 0;

    vector<pair<char, int>> runs;
    runs.reserve(s.size());

    for (char ch : s)
    {
        if (ch == prev)
            ++cnt;
        else
        {
            if (cnt)
                runs.emplace_back(prev, cnt);
            prev = ch;
            cnt = 1;
        }
    }

    if (cnt)
        runs.emplace_back(prev, cnt);

    for (size_t i = 0; i + 2 < runs.size(); ++i)
    {
        if (runs[i].first == 'J' && runs[i + 1].first == 'O' && runs[i + 2].first == 'I')
        {
            best = max(best, min({runs[i].second, runs[i + 1].second, runs[i + 2].second}));
        }
    }

    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (cin >> s)
    {
        cout << solve(s) << "\n";
    }

    return 0;
}