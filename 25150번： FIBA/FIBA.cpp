#include <bits/stdc++.h>
using namespace std;

struct Team
{
    int label, points, total_scores;
};

int main()
{
    int N, K, H;
    cin >> N >> K >> H;

    vector<Team> teams(N + 1);

    for (int i = 1; i <= N; i++)
    {
        teams[i].label = i;
        teams[i].points = 0;
        teams[i].total_scores = 0;
    }

    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int Ki, Kj;
            cin >> Ki >> Kj;
            teams[i].total_scores += Ki;
            teams[j].total_scores += Kj;
            if (Ki > Kj)
            {
                teams[i].points += 2;
                teams[j].points += 1;
            }
            else
            {
                teams[i].points += 1;
                teams[j].points += 2;
            }
        }
    }

    cout << teams[H].points << "\n";

    int max_points = -1;
    int max_scores = -1;
    int winner = -1;

    for (int i = 1; i <= N; i++)
    {
        if (teams[i].points > max_points)
        {
            max_points = teams[i].points;
            max_scores = teams[i].total_scores;
            winner = teams[i].label;
        }
        else if (teams[i].points == max_points)
        {
            if (teams[i].total_scores > max_scores)
            {
                max_scores = teams[i].total_scores;
                winner = teams[i].label;
            }
        }
    }

    cout << winner << "\n";
    long long carried_over = 3LL * K * (K - 1) / 2;
    cout << carried_over << "\n";

    return 0;
}