#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int I, N, K;
    if (!(cin >> I >> N >> K)) return 0;
    
    string ink;
    cin >> ink;

    vector<string> g(N);
    pair<int, int> pos{-1, -1};
    
    for (int i = 0; i < N; ++i) {
        cin >> g[i];
        for (int j = 0; j < N; ++j) if (g[i][j] == '@') { pos = {i,j}; g[i][j] = '.'; }
    }

    string cmd;
    cin >> cmd;

    auto inb = [&](int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; };
    auto isObs = [&] (char c) { return c == '#' || ('A' <= c && c <= 'Z'); };

    int ink_amt = 0, jump_cnt = 0;
    map<char, pair<int, int>> mv{{'U', {-1,0}},{'D', {1,0}}, {'L', {0,-1}}, {'R', {0,1}}};

    for (char c: cmd) {
        if (c == 'j') { ++ink_amt; }
        else if (c == 'J') {
            char col = ink[jump_cnt % I];
            int y = pos.first, x = pos.second;
            for (int dy = -ink_amt; dy <= ink_amt; ++dy) {
                int rem = ink_amt - abs(dy);
                for (int dx = -rem; dx <= rem; ++dx) {
                    int ny = y + dy, nx = x + dx;
                    if (!inb(ny, nx)) continue;
                    if (isObs(g[ny][nx])) g[ny][nx] = col;
                }
            }

            ink_amt = 0;
            ++jump_cnt;
        } else {
            auto [dy, dx] = mv[c];
            int ny = pos.first + dy, nx = pos.second + dx;
            if (inb(ny, nx) && !isObs(g[ny][nx])) pos = {ny,nx};
        }
    }

    g[pos.first][pos.second] = '@';
    for (int i = 0; i < N; ++i) cout << g[i] << '\n';
    return 0;
}