#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

vector<double> compute_d20_distribution(const string &mode)
{
    vector<double> dist(21, 0.0);
    if (mode == "straight")
    {
        for (int i = 1; i <= 20; i++)
        {
            dist[i] = 1.0 / 20.0;
        }
    }
    else if (mode == "advantage")
    {
        vector<int> freq(21, 0);
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                int result = max(i, j);
                freq[result]++;
            }
        }
        for (int r = 1; r <= 20; r++)
        {
            dist[r] = freq[r] / 400.0;
        }
    }
    else if (mode == "disadvantage")
    {
        vector<int> freq(21, 0);
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                int result = min(i, j);
                freq[result]++;
            }
        }
        for (int r = 1; r <= 20; r++)
        {
            dist[r] = freq[r] / 400.0;
        }
    }

    return dist;
}

map<int, double> compute_bonus_distribution(int k, const vector<string> &dice)
{
    map<int, double> dp;
    dp[0] = 1.0;
    for (int i = 0; i < k; i++)
    {
        map<int, double> next_dp;
        char sign = dice[i][0];
        int d = stoi(dice[i].substr(2));

        for (auto &[curr, prob] : dp)
        {
            for (int face = 1; face <= d; face++)
            {
                int add = (sign == '+') ? face : -face;
                next_dp[curr + add] += prob * (1.0 / d);
            }
        }
        dp = next_dp;
    }

    return dp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, m;
    cin >> d >> m;
    string mode;
    cin >> mode;

    int k;
    cin >> k;

    vector<string> bonusDice(k);

    for (int i = 0; i < k; i++)
    {
        cin >> bonusDice[i];
    }

    vector<double> d20 = compute_d20_distribution(mode);

    map<int, double> bonusDist = compute_bonus_distribution(k, bonusDice);

    double successProb = 0.0;

    for (int r = 1; r <= 20; r++)
    {
        double pr = d20[r];
        if (r == 20)
        {
            successProb += pr;
            continue;
        }

        if (r == 1)
        {
            continue;
        }

        for (auto &[bonus, bonusProb] : bonusDist)
        {
            int total = r + m + bonus;
            if (total >= d)
            {
                successProb += pr * bonusProb;
            }
        }
    }

    cout << fixed << setprecision(9) << successProb << "\n";
    return 0;
}
