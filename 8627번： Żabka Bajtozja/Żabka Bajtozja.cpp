#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, s;
    cin >> n >> p >> s;
    vector<Point> stones(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i].x >> stones[i].y;
    }

    vector<bool> visited(n, false);
    queue<int> q;
    int start = p - 1;
    visited[start] = true;
    q.push(start);

    double maxDist = 0.0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        double dx = stones[cur].x - stones[start].x;
        double dy = stones[cur].y - stones[start].y;
        double d = sqrt(dx * dx + dy * dy);
        if (d > maxDist)
            maxDist = d;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                long long dx2 = (long long)stones[cur].x - stones[i].x;
                long long dy2 = (long long)stones[cur].y - stones[i].y;
                if (dx2 * dx2 + dy2 * dy2 <= (long long)s * s)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    double result = maxDist + s;
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << result << "\n";
    return 0;
}
