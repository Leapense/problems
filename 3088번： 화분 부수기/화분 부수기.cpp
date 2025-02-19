#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<array<int, 3>> pots(N);

    for (int i = 0; i < N; i++)
    {
        cin >> pots[i][0] >> pots[i][1] >> pots[i][2];
    }

    vector<bool> active(1000001, false);
    int manualBreaks = 0;

    for (int i = 0; i < N; i++)
    {
        bool brokenAutomatically = false;
        for (int j = 0; j < 3; j++)
        {
            if (active[pots[i][j]])
            {
                brokenAutomatically = true;
                break;
            }
        }

        if (!brokenAutomatically)
        {
            manualBreaks++;
        }

        for (int j = 0; j < 3; j++)
        {
            active[pots[i][j]] = true;
        }
    }

    cout << manualBreaks << "\n";
    return 0;
}