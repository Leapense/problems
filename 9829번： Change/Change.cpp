#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n5, n10, n20, n50, target;

    cin >> n5 >> n10 >> n20 >> n50 >> target;
    if (target % 5 != 0)
    {
        cout << -1;
        return 0;
    }

    int T = target / 5;
    int max50 = min(n50, T / 10);
    int best = 1e9;
    int best50 = -1, best20 = -1, best10 = -1, best5 = -1;
    for (int x50 = max50; x50 >= 0; x50--)
    {
        int rem = T - 10 * x50;
        if (rem < 0)
            continue;
        int use20 = min(n20, rem / 4);
        int rem1 = rem - 4 * use20;
        int use10 = min(n10, rem1 / 2);
        int rem2 = rem1 - 2 * use10;
        int use5 = rem2;

        if (use5 > n5)
            continue;
        int coins = x50 + use20 + use10 + use5;
        if (coins < best)
        {
            best = coins;
            best50 = x50;
            best20 = use20;
            best10 = use10;
            best5 = use5;
        }

        if (best == x50 + rem)
            break;
    }

    if (best50 < 0)
    {
        cout << -1;
    }
    else
    {
        cout << best5 << " " << best10 << " " << best20 << " " << best50 << " " << best;
    }

    return 0;
}