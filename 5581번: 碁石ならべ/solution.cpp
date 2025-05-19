#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // store runs as (color, count)
    vector<pair<int, int>> runs;
    runs.reserve(n);

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;

        if (runs.empty())
        {
            runs.emplace_back(c, 1);
        }
        else
        {
            auto &last = runs.back();
            if (i % 2 == 1)
            {
                // odd step: simply place
                if (last.first == c)
                {
                    // extend current run
                    last.second++;
                }
                else
                {
                    runs.emplace_back(c, 1);
                }
            }
            else
            {
                // even step
                if (last.first == c)
                {
                    // same color → just extend
                    last.second++;
                }
                else
                {
                    // flip the entire last run to 'c' and add the new stone
                    last.first = c;
                    last.second++;

                    // **merge** with previous run if it's the same color
                    int m = runs.size();
                    if (m >= 2 && runs[m - 2].first == c)
                    {
                        runs[m - 2].second += runs[m - 1].second;
                        runs.pop_back();
                    }
                }
            }
        }
    }

    // count whites (color==0)
    long long white = 0;
    for (auto &r : runs)
        if (r.first == 0)
            white += r.second;

    cout << white << "\n";
    return 0;
}
