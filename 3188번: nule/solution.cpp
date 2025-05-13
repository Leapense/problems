#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> a(N+1, vector<int>(N+1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> e2(N+1, vector<int>(N+1));
    vector<vector<int>> e5(N+1, vector<int>(N+1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int v = a[i][j];
            if (v == 0) 
            {
                e2[i][j] = e5[i][j] = INF;
            }
            else
            {
                int c2 = 0, c5 = 0;
                int t = v;
                while (t % 2 == 0) { c2++; t /= 2; }
                t = v;
                while (t % 5 == 0) { c5++; t /= 5; }

                e2[i][j] = c2;
                e5[i][j] = c5;
            }
        }
    }

    vector<vector<int>> dp2(N+1, vector<int>(N+1, INF));
    vector<vector<int>> dp5(N+1, vector<int>(N+1, INF));

    if (a[1][1] != 0) 
    {
        dp2[1][1] = e2[1][1];
        dp5[1][1] = e5[1][1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (a[i][j] == 0) continue;
            if (i > 1 && dp2[i-1][j] < INF)
            {
                dp2[i][j] = min(dp2[i][j], dp2[i-1][j] + e2[i][j]);
                dp5[i][j] = min(dp5[i][j], dp5[i-1][j] + e5[i][j]);
            }
            if (j > 1 && dp2[i][j-1] < INF)
            {
                dp2[i][j] = min(dp2[i][j], dp2[i][j-1] + e2[i][j]);
                dp5[i][j] = min(dp5[i][j], dp5[i][j-1] + e5[i][j]);
            }
        }
    }

    int ans2 = dp2[N][N];
    int ans5 = dp5[N][N];
    int answer = min(ans2, ans5);
    cout << answer << "\n";
    return 0;
}