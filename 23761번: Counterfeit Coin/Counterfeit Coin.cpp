#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int maxMoves = (n + 1) / 2;
    int used = 0;

    vector<pair<int, int>> notEqualPairs;
    int refCoin = -1;
    bool foundRef = false;

    int pairsCount = n / 2;

    for (int i = 0; i < pairsCount && used < maxMoves; i++)
    {
        int c1 = 2 * i + 1;
        int c2 = 2 * i + 2;
        cout << "? " << c1 << " " << c2 << "\n";
        cout.flush();
        used++;

        string res;
        cin >> res;

        if (res == "equal")
        {
            if (!foundRef)
            {
                refCoin = c1;
                foundRef = true;
            }
        }
        else
        {
            notEqualPairs.push_back({c1, c2});
        }
    }

    int leftover = (n % 2 == 1) ? n : -1;
    if (leftover != -1 && used < maxMoves && foundRef)
    {
        cout << "? " << refCoin << " " << leftover << "\n";
        cout.flush();
        used++;

        string res;
        cin >> res;
        if (res == "equal")
        {
            cout << "! " << leftover << "\n";
            return 0;
        }
    }

    if (foundRef)
    {
        for (auto &pp : notEqualPairs)
        {
            if (used >= maxMoves)
                break;
            cout << "? " << refCoin << " " << pp.first << "\n";
            cout.flush();
            used++;

            string res;
            cin >> res;

            if (res != "equal")
            {
                cout << "! " << pp.first << "\n";
                return 0;
            }

            if (used < maxMoves)
            {
                cout << "? " << refCoin << " " << pp.second << "\n";
                cout.flush();
                used++;

                cin >> res;

                if (res != "equal")
                {
                    cout << "! " << pp.second << "\n";
                    return 0;
                }
            }
            else
            {
                cout << "! " << pp.second << "\n";
                return 0;
            }
        }

        cout << "! " << refCoin << "\n";
        return 0;
    }

    if (!notEqualPairs.empty())
    {
        cout << "! " << notEqualPairs[0].first << "\n";
        return 0;
    }

    if (leftover != -1)
    {
        cout << "! " << leftover << "\n";
    }
    else
    {
        cout << "! 1\n";
    }

    return 0;
}