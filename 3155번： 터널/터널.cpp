#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> ceilArr(N + 1), floorArr(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> ceilArr[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> floorArr[i];
    }
    int offset = 1000, range = 2001;
    // allowed[i] : [L[i], R[i]] = [floor[i]+1, ceil[i]-1]
    vector<int> L(N + 1), R(N + 1);
    for (int i = 1; i <= N; i++)
    {
        L[i] = floorArr[i] + 1;
        R[i] = ceilArr[i] - 1;
    }
    // dp[i][j] : 최소 비용, j state는 실제 y = j-offset.
    vector<vector<int>> dp(N + 1, vector<int>(range, INF));
    // predecessor[i][j] : dp[i][j] 선택 시 이전 상태
    vector<vector<int>> pre(N + 1, vector<int>(range, -1));
    // 시작: column 0, y=0 -> state = offset.
    dp[0][offset] = 0;
    for (int i = 1; i <= N; i++)
    {
        // i번째 열에서는 j such that y = j-offset in [L[i], R[i]]
        int lowState = L[i] + offset, highState = R[i] + offset;
        for (int j = lowState; j <= highState; j++)
        {
            for (int u = 0; u < range; u++)
            {
                if (dp[i - 1][u] == INF)
                    continue;
                int cost = dp[i - 1][u] + abs(j - u);
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    pre[i][j] = u;
                }
                else if (cost == dp[i][j])
                {
                    // tie-break: if j > u then 선호: 작은 u, 만약 j < u면 큰 u.
                    int cand = u, cur = pre[i][j];
                    if (j > u && cand < cur)
                        pre[i][j] = u;
                    else if (j < u && cand > cur)
                        pre[i][j] = u;
                }
            }
        }
    }
    int endState = offset; // y = 0
    int best = dp[N][endState];
    int curState = endState;
    vector<int> path(N + 1);
    path[N] = curState - offset;
    for (int i = N; i >= 1; i--)
    {
        curState = pre[i][curState];
        path[i - 1] = curState - offset;
    }
    // 출력: 열 1부터 N의 y좌표 (시작점 0은 생략)
    for (int i = 1; i <= N; i++)
    {
        cout << path[i] << (i == N ? "\n" : " ");
    }
    return 0;
}
