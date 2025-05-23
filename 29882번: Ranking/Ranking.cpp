#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<string, unordered_map<string, int>> scoreBoard;

    for (int i = 0; i < N; i++)
    {
        string account, task;
        int score;
        cin >> account >> task >> score;

        if (scoreBoard[account].find(task) == scoreBoard[account].end())
        {
            scoreBoard[account][task] = score;
        }
        else
        {
            scoreBoard[account][task] = max(scoreBoard[account][task], score);
        }
    }

    vector<pair<string, int>> ranking;
    for (auto &entry : scoreBoard)
    {
        int total = 0;
        for (auto &taskScore : entry.second)
        {
            total += taskScore.second;
        }
        ranking.push_back({entry.first, total});
    }

    sort(ranking.begin(), ranking.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         { return a.second > b.second; });

    for (auto &p : ranking)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}