#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int r, c, d;
};

struct Node
{
    int r, c;
};

int n, m;
vector<string> grid;

int calcDist(int r, int c)
{
    return (r - 1) + (c - 1);
}

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
const char mv[4] = {'D', 'U', 'R', 'L'};

class Solver
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }
        vector<Cell> clues;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'X')
                {
                    clues.push_back({i, j, calcDist(i + 1, j + 1)});
                }
            }
        }
        sort(clues.begin(), clues.end(), [](const Cell &a, const Cell &b)
             {
            if(a.d != b.d) return a.d < b.d;
            if(a.r != b.r) return a.r < b.r;
            return a.c < b.c; });
        vector<vector<bool>> collected(n, vector<bool>(m, false));
        string ans = "";
        int cr = 0, cc = 0;

        auto bfsPath = [&](int tr, int tc, int targetD) -> string
        {
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            vector<vector<int>> pr(n, vector<int>(m, -1));
            vector<vector<int>> pc(n, vector<int>(m, -1));
            vector<vector<int>> pm(n, vector<int>(m, -1));
            queue<Node> q;
            q.push({cr, cc});
            vis[cr][cc] = true;
            bool found = false;
            int er = -1, ec = -1;
            while (!q.empty())
            {
                Node cur = q.front();
                q.pop();
                if (cur.r == tr && cur.c == tc)
                {
                    found = true;
                    er = cur.r;
                    ec = cur.c;
                    break;
                }
                if (!collected[cur.r][cur.c] && grid[cur.r][cur.c] == 'X')
                {
                    int cd = calcDist(cur.r + 1, cur.c + 1);
                    if (cd == targetD && cur.r == tr && cur.c == tc)
                    {
                        found = true;
                        er = cur.r;
                        ec = cur.c;
                        break;
                    }
                }
                for (int k = 0; k < 4; k++)
                {
                    int nr = (cur.r + dr[k] + n) % n;
                    int nc = (cur.c + dc[k] + m) % m;
                    if (!vis[nr][nc])
                    {
                        if (grid[nr][nc] == 'X' && !collected[nr][nc])
                        {
                            int nd = calcDist(nr + 1, nc + 1);
                            if (nd > targetD)
                                continue;
                        }
                        vis[nr][nc] = true;
                        pr[nr][nc] = cur.r;
                        pc[nr][nc] = cur.c;
                        pm[nr][nc] = k;
                        q.push({nr, nc});
                    }
                }
            }
            if (!found)
                return "";
            string path = "";
            int r = er, c = ec;
            while (r != cr || c != cc)
            {
                int dir = pm[r][c];
                path.push_back(mv[dir]);
                int prr = pr[r][c], prc = pc[r][c];
                r = prr;
                c = prc;
            }
            reverse(path.begin(), path.end());
            return path;
        };

        for (auto &cell : clues)
        {
            if (collected[cell.r][cell.c])
                continue;
            if (cr == cell.r && cc == cell.c)
            {
                collected[cell.r][cell.c] = true;
                continue;
            }
            int targetD = cell.d;
            string pathSegment = bfsPath(cell.r, cell.c, targetD);
            if (pathSegment == "")
            {
                if (cr == cell.r && cc == cell.c)
                    collected[cell.r][cell.c] = true;
                continue;
            }
            for (char ch : pathSegment)
            {
                if (ch == 'D')
                    cr = (cr + 1 < n ? cr + 1 : 0);
                else if (ch == 'U')
                    cr = (cr - 1 >= 0 ? cr - 1 : n - 1);
                else if (ch == 'R')
                    cc = (cc + 1 < m ? cc + 1 : 0);
                else if (ch == 'L')
                    cc = (cc - 1 >= 0 ? cc - 1 : m - 1);
                ans.push_back(ch);
                if (grid[cr][cc] == 'X' && !collected[cr][cc])
                    collected[cr][cc] = true;
            }
        }

        cout << ans << "\n";
    }
};

int main()
{
    Solver solver;
    solver.solve();
    return 0;
}