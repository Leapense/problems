#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> cards(m + 1);
        for (int i = 0; i < k; i++)
        {
            int r, s;
            cin >> r >> s;
            cards[s].push_back(r);
        }

        int ans = 0;
        for (int suit = 1; suit <= m; suit++)
        {
            if (cards[suit].empty())
                continue;
            sort(cards[suit].begin(), cards[suit].end());
            cards[suit].erase(unique(cards[suit].begin(), cards[suit].end()), cards[suit].end());

            int current = 1;
            int max_consecutive = 0;
            for (size_t i = 1; i < cards[suit].size(); i++)
            {
                if (cards[suit][i] == cards[suit][i - 1] + 1)
                {
                    current++;
                }
                else
                {
                    max_consecutive = max(max_consecutive, current);
                    current = 1;
                }
            }
            max_consecutive = max(max_consecutive, current);
            ans = max(ans, max_consecutive);
        }

        cout << (ans >= 2 ? ans : 0) << "\n";
    }

    return 0;
}