#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        vector<vector<int>> bestScore(n + 1, vector<int>(k + 1, 0));
        vector<int> submissionCount(n + 1, 0);
        vector<int> lastSubmission(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            int team, prob, score;
            cin >> team >> prob >> score;

            submissionCount[team]++;
            lastSubmission[team] = i;
            if (score > bestScore[team][prob])
            {
                bestScore[team][prob] = score;
            }
        }

        vector<tuple<int, int, int, int>> teams;
        for (int i = 1; i <= n; i++)
        {
            int total = 0;
            for (int j = 1; j <= k; j++)
            {
                total += bestScore[i][j];
            }

            teams.push_back(make_tuple(total, submissionCount[i], lastSubmission[i], i));
        }

        sort(teams.begin(), teams.end(), [](auto a, auto b)
             {
            if (get<0>(a) != get<0>(b)) {
                return get<0>(a) > get<0>(b);
            }
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) < get<1>(b);
            }
            return get<2>(a) < get<2>(b); });

        int rank = 0;
        for (auto &entry : teams)
        {
            rank++;
            if (get<3>(entry) == t)
            {
                cout << rank << "\n";
                break;
            }
        }
    }

    return 0;
}