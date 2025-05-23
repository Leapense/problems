#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int D;
        cin >> D;
        vector<int> pancakes(D);
        int maxP = 0;
        for (int i = 0; i < D; i++)
        {
            cin >> pancakes[i];
            maxP = max(maxP, pancakes[i]);
        }

        int best = maxP;
        for (int x = 1; x <= maxP; x++)
        {
            int moves = 0;
            for (int p : pancakes)
            {
                moves += (p - 1) / x;
            }

            best = min(best, x + moves);
        }

        cout << "Case #" << t << ": " << best;
        if (t < T)
            cout << "\n";
    }

    return 0;
}