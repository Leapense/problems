#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;

        vector<int> cards(N);
        for (int i = 0; i < N; i++)
        {
            cin >> cards[i];
        }

        vector<int> compressed;
        compressed.push_back(cards[0]);
        for (int i = 1; i < N; i++)
        {
            if (cards[i] != cards[i - 1])
            {
                compressed.push_back(cards[i]);
            }
        }
        bool possible = true;
        int sz = compressed.size();
        vector<bool> seen(100001, false);
        for (int i = 0; i < sz; i++)
        {
            int color = compressed[i];
            if (seen[color])
            {
                possible = false;
                break;
            }
            seen[color] = true;
        }

        cout << "Case #" << t << ": ";
        if (!possible)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            for (int i = 0; i < sz; i++)
            {
                cout << compressed[i];
                if (i != sz - 1)
                    cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}