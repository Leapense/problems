#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> pts(N);

    int maxX = 0, maxY = 0;

    for (int i = 0; i < N; i++) {
        cin >> pts[i].first >> pts[i].second;
        maxX = max(maxX, pts[i].first);
        maxY = max(maxY, pts[i].second);
    }

    vector<long long> cntX(maxX + 1, 0), cntY(maxY + 1, 0);
    for (auto &p : pts) {
        cntX[p.first]++;
        cntY[p.second]++;
    }

    long long answer = 0;
    for (auto &p : pts) {
        long long vx = cntX[p.first] - 1;
        long long hy = cntY[p.second] - 1;
        if (vx > 0 && hy > 0) {
            answer += vx * hy;
        }
    }

    cout << answer << "\n";

    return 0;
}