#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, S;
    if (!(cin >> R >> S)) return 0;
    
    vector<string> g(R);
    for (auto& row : g) cin >> row;
    
    int sr, sc;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            if (g[i][j] == 'o') {
                sr = i;
                sc = j;
            }
        }
    }

    constexpr int dr4[4] = {-1, 0, 1, 0};
    constexpr int dc4[4] = {0, 1, 0, -1};
    constexpr char dir4[4] = {'N', 'E', 'S', 'W'};
    int bestLen = INT_MAX;
    char bestDir = 0;
    for (int d = 0; d < 4; ++d)
    {
        int r = sr + dr4[d], c = sc + dc4[d], step = 1;
        if (r < 0 || r >= R || c < 0 || c >= S) continue;
        while (true) {
            char ch = g[r][c];
            if (ch == 'x') {
                if (step < bestLen || (step == bestLen && dir4[d] < bestDir)) {
                    bestLen = step;
                    bestDir = dir4[d];
                }
                break;
            }

            if (ch == '.' || (r == sr && c == sc)) break;

            int nr = r, nc = c;
            if (ch == 'v') nr++;
            else if (ch == '^') nr--;
            else if (ch == '<') nc--;
            else if (ch == '>') nc++;
            else break;
            r = nr; c = nc; ++step;
        }
    }

    if (!bestDir) cout << ":(\n";
    else cout << ":)\n" << bestDir << '\n';
    return 0;
}