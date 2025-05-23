#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Point> cities(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cities[i].x >> cities[i].y;
    }

    long long ans = numeric_limits<long long>::max();

    for (int start = 0; start < n; start++)
    {
        vector<bool> visited(n, false);
        visited[start] = true;
        int count = 1;
        int cur = start;
        long long totalTime = 0;

        while (count < n)
        {
            long long bestDist = numeric_limits<long long>::max();
            int bestIndex = -1;

            for (int j = 0; j < n; j++)
            {
                if (!visited[j])
                {
                    long long dx = cities[cur].x - cities[j].x;
                    long long dy = cities[cur].y - cities[j].y;
                    long long dist = dx * dx + dy * dy;
                    if (dist < bestDist || (dist == bestDist && j < bestIndex))
                    {
                        bestDist = dist;
                        bestIndex = j;
                    }
                }
            }

            totalTime += bestDist;
            cur = bestIndex;
            visited[cur] = true;
            count++;
        }
        ans = min(ans, totalTime);
    }

    cout << ans;

    return 0;
}