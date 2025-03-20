#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getCoords(int num)
{
    return {(num - 1) / 3, (num - 1) % 3};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;

    vector<int> pattern(L);
    for (int i = 0; i < L; i++)
    {
        cin >> pattern[i];
    }

    vector<bool> visited(10, false);
    for (int num : pattern)
    {
        if (visited[num])
        {
            cout << "NO";
            return 0;
        }

        visited[num] = true;
    }

    fill(visited.begin(), visited.end(), false);

    visited[pattern[0]] = true;

    for (int i = 1; i < L; i++)
    {
        int from = pattern[i - 1];
        int to = pattern[i];
        auto [r1, c1] = getCoords(from);
        auto [r2, c2] = getCoords(to);

        if ((r1 + r2) % 2 == 0 && (c1 + c2) % 2 == 0)
        {
            int mid = (r1 + r2) / 2 * 3 + (c1 + c2) / 2 + 1;

            if (!visited[mid])
            {
                cout << "NO";
                return 0;
            }
        }

        visited[to] = true;
    }

    cout << "YES";
    return 0;
}