#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H, L;
    cin >> N >> H >> L;

    vector<int> horrorIndex(N, numeric_limits<int>::max());
    vector<vector<int>> adj(N);

    for (int i = 0; i < H; i++)
    {
        int hMovie;
        cin >> hMovie;
        horrorIndex[hMovie] = 0;
    }

    for (int i = 0; i < L; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (horrorIndex[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (auto &next : adj[current])
        {
            if (horrorIndex[next] == numeric_limits<int>::max())
            {
                horrorIndex[next] = horrorIndex[current] + 1;
                q.push(next);
            }
        }
    }

    int bestMovie = -1;
    bool hasInfinite = false;

    for (int i = 0; i < N; i++)
    {
        if (horrorIndex[i] == numeric_limits<int>::max())
        {
            hasInfinite = true;
            if (bestMovie == -1 || i < bestMovie)
            {
                bestMovie = i;
            }
        }
    }

    if (!hasInfinite)
    {
        int maxHI = -1;
        for (int i = 0; i < N; i++)
        {
            if (horrorIndex[i] > maxHI)
            {
                maxHI = horrorIndex[i];
                bestMovie = i;
            }
        }
    }

    cout << bestMovie << "\n";
    return 0;
}