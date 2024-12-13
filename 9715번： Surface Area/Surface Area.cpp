#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int R, C;
        cin >> R >> C;
        vector<string> grid(R);

        for (int i = 0; i < R; ++i) {
            cin >> grid[i];
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        long long surface = 0;

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                int h = grid[r][c] - '0';
                if (h > 0) {
                    surface += 2;

                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        int nh = 0;
                        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                            nh = grid[nr][nc] - '0';
                        }
                        if (h > nh) {
                            surface += (h - nh);
                        }
                    }
                }
            }
        }

        cout << surface << "\n";
    }

    return 0;
}