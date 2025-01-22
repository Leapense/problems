#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> candidates;

    for (int i = 1; i <= n; i++)
        candidates.push_back(i);

    int max_moves = (n + 1) / 2;
    int moves = 0;

    while (moves < max_moves && candidates.size() > 1)
    {
        if (candidates.size() >= 2)
        {
            int x = candidates[0];
            int y = candidates[1];
            cout << "? " << x << " " << y << "\n";
            cout.flush();

            string response;
            cin >> response;
            if (response == "equal")
            {
                candidates.erase(candidates.begin(), candidates.begin() + 2);
            }
            else
            {
                candidates.erase(candidates.begin() + 1);
                candidates.erase(candidates.begin());
            }

            moves++;
        }
        else
        {
            break;
        }
    }

    if (candidates.empty())
    {
        cout << "! 1\n";
    }
    else
    {
        cout << "! " << candidates[0] << "\n";
    }

    return 0;
}