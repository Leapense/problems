#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M, K;
    if (!(cin >> N >> M >> K)) return 0;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    long long totalZero = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == 0) ++totalZero;
        }
    }

    if (totalZero == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<vector<char>> vis(N, vector<char>(N, 0));
    long long R = 0;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == 0 && !vis[i][j]) {
                long long S = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto [x,y] = q.front(); q.pop();
                    ++S;
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (0 <= nx && nx < N && 0 <= ny && ny < N && !vis[nx][ny] && a[nx][ny] == 0) {
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        } 
                    }
                }

                long long need = (S + K - 1) / K;
                R += need;
            }
        }
    }

    if (M >= R && R >= 1) cout << "POSSIBLE\n" << (M - R) << "\n";
    else cout << "IMPOSSIBLE\n";
    return 0;
}