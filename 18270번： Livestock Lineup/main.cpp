#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    int n;
    cin >> n;
    vector<pair<string, string>> cons;
    for (int i = 0; i < n; i++)
    {
        string a, temp, b;
        cin >> a;
        for (int j = 0; j < 4; j++)
            cin >> temp;
        cin >> b;
        cons.push_back({a, b});
    }
    do
    {
        bool ok = true;
        for (auto &p : cons)
        {
            int pos1 = -1, pos2 = -1;
            for (int i = 0; i < 8; i++)
            {
                if (cows[i] == p.first)
                    pos1 = i;
                if (cows[i] == p.second)
                    pos2 = i;
            }
            if (abs(pos1 - pos2) != 1)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            for (auto &s : cows)
                cout << s << "\n";
            return 0;
        }
    } while (next_permutation(cows.begin(), cows.end()));
    return 0;
}