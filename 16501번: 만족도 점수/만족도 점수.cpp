#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to compute the best satisfaction for a group of 4 players
double bestGameSatisfaction(const vector<int> &scores)
{
    // There are exactly 3 ways to partition 4 players into two teams of 2.
    // Option 1: teams: (0,1) and (2,3)
    double s1 = 1.0 - (abs((scores[0] + scores[1]) - (scores[2] + scores[3])) / 20.0);
    // Option 2: teams: (0,2) and (1,3)
    double s2 = 1.0 - (abs((scores[0] + scores[2]) - (scores[1] + scores[3])) / 20.0);
    // Option 3: teams: (0,3) and (1,2)
    double s3 = 1.0 - (abs((scores[0] + scores[3]) - (scores[1] + scores[2])) / 20.0);

    return max(s1, max(s2, s3));
}

int main()
{
    vector<int> skills(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> skills[i];
    }

    double bestOverall = 0.0;
    // We use bitmask to choose 4 out of 8 players for the first game.
    // To avoid duplicate partitions, ensure that player 0 is always in the first game.
    for (int mask = 0; mask < (1 << 8); mask++)
    {
        if (__builtin_popcount(mask) != 4)
            continue;
        if (!(mask & 1))
            continue; // Ensure player 0 is included

        vector<int> game1, game2;
        for (int i = 0; i < 8; i++)
        {
            if (mask & (1 << i))
                game1.push_back(skills[i]);
            else
                game2.push_back(skills[i]);
        }

        double sat1 = bestGameSatisfaction(game1);
        double sat2 = bestGameSatisfaction(game2);
        double currMin = min(sat1, sat2);
        bestOverall = max(bestOverall, currMin);
    }

    // Output formatting: if answer*10 is an integer, use one decimal; otherwise, two decimals.
    double scaled = bestOverall * 10;
    if (fabs(scaled - round(scaled)) < 1e-9)
    {
        cout << fixed << setprecision(1) << bestOverall << "\n";
    }
    else
    {
        cout << fixed << setprecision(2) << bestOverall << "\n";
    }

    return 0;
}
