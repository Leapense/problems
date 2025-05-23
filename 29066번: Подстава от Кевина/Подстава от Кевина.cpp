#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> boards(n);

    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        boards[i] = {weight, i + 1};
    }

    sort(boards.begin(), boards.end());

    for (int i = 0; i < n; i++)
    {
        int a = boards[i].first;
        int lowerBound = a + y;
        int upperBound = x - a;

        if (lowerBound > upperBound)
        {
            continue;
        }

        auto it = lower_bound(boards.begin() + i + 1, boards.end(), make_pair(lowerBound, -1));

        if (it != boards.end() && it->first <= upperBound)
        {
            cout << boards[i].second << " " << it->second;
            return 0;
        }
    }

    cout << 0;
    return 0;
}