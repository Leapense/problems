#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> score(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> score[i];
    }

    int best = -1;
    vector<int> indices1, indices2;

    for (int mask = 0; mask < (1 << 8); mask++)
    {
        if (__builtin_popcount(mask) != 4)
            continue;
        indices1.clear();
        indices2.clear();

        for (int i = 0; i < 8; i++)
        {
            if (mask & (1 << i))
                indices1.push_back(i);
            else
                indices2.push_back(i);
        }

        vector<vector<int>> splits = {{0, 1, 2, 3}, {0, 2, 1, 3}, {0, 3, 1, 2}};

        for (auto s1 : splits)
        {
            int sum1_team1 = score[indices1[s1[0]]] + score[indices1[s1[1]]];
            int sum1_team2 = score[indices1[s1[2]]] + score[indices1[s1[3]]];

            int diff1 = abs(sum1_team1 - sum1_team2);
            for (auto s2 : splits)
            {
                int sum2_team1 = score[indices2[s2[0]]] + score[indices2[s2[1]]];
                int sum2_team2 = score[indices2[s2[2]]] + score[indices2[s2[3]]];

                int diff2 = abs(sum2_team1 - sum2_team2);
                int cur = 20 - max(diff1, diff2);
                best = max(best, cur);
            }
        }
    }

    double res = static_cast<double>(best) / 20.0;
    if ((best % 2) == 0)
        cout << fixed << res << "\n";
    else
        cout << fixed << setprecision(2) << res << "\n";

    return 0;
}