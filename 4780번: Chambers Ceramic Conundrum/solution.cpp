// solution.cpp
// Compile normally:     g++ -std=c++26 -O2 solution.cpp
// Compile for tests:    g++ -std=c++26 -DUNIT_TEST -O2 -I<gtest-path> -c solution.cpp
#include <bits/stdc++.h>
using namespace std;

struct Placement
{
    int tileIdx, dx, dy, orientIdx;
};

struct Solver
{
    vector<vector<vector<pair<int, int>>>> shapes; // 7 × 4 × 4
    vector<int> tiles;                             // 9 numbers, 1-based
    char grid[6][6]{};
    vector<Placement> answer;

    unordered_set<uint64_t> failed;           // memo of dead states
    unordered_map<uint64_t, bool> regionMemo; // mask → hole-OK?
    vector<vector<int>> nbrs;                 // 4-neighbour list

    explicit Solver(const vector<int> &t) : tiles(t)
    {
        initShapes();
        memset(grid, '.', sizeof(grid));
        buildNbrs();
    }

    /* ---------- geometry -------------------------------------------------- */
    void initShapes()
    {
        shapes.resize(7);
        vector<vector<pair<int, int>>> base(7);
        base[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}}; // I
        base[1] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}}; // O
        base[2] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}}; // Z
        base[3] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}}; // S
        base[4] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}}; // J
        base[5] = {{0, 0}, {1, 0}, {2, 0}, {0, 1}}; // L
        base[6] = {{1, 0}, {0, 1}, {1, 1}, {2, 1}}; // T

        for (int s = 0; s < 7; ++s)
        {
            auto cfg = base[s];
            for (int r = 0; r < 4; ++r)
            {
                int minx = INT_MAX, miny = INT_MAX;
                for (auto &p : cfg)
                {
                    minx = min(minx, p.first);
                    miny = min(miny, p.second);
                }
                vector<pair<int, int>> norm;
                for (auto &p : cfg)
                    norm.push_back({p.first - minx, p.second - miny});
                shapes[s].push_back(norm);

                vector<pair<int, int>> nxt;
                for (auto &p : cfg)
                    nxt.push_back({p.second, -p.first}); // 90° CW
                cfg.swap(nxt);
            }
        }
    }

    void buildNbrs()
    {
        nbrs.resize(36);
        for (int i = 0; i < 36; ++i)
        {
            int x = i % 6, y = i / 6;
            if (x > 0)
                nbrs[i].push_back(i - 1);
            if (x < 5)
                nbrs[i].push_back(i + 1);
            if (y > 0)
                nbrs[i].push_back(i - 6);
            if (y < 5)
                nbrs[i].push_back(i + 6);
        }
    }

    /* ---------- hole multiple-of-4 filter --------------------------------- */
    bool holesOk(uint64_t mask)
    {
        auto it = regionMemo.find(mask);
        if (it != regionMemo.end())
            return it->second;

        bool vis[36] = {};
        for (int i = 0; i < 36; ++i)
            if (!(mask >> i & 1) && !vis[i])
            {
                int cnt = 0;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while (!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    ++cnt;
                    for (int nb : nbrs[v])
                        if (!(mask >> nb & 1) && !vis[nb])
                        {
                            vis[nb] = true;
                            q.push(nb);
                        }
                }
                if (cnt % 4)
                {
                    regionMemo[mask] = false;
                    return false;
                }
            }
        regionMemo[mask] = true;
        return true;
    }

    /* ---------- depth-first search (tiler’s order) ------------------------ */
    bool dfs(uint64_t mask, int used)
    {
        if (mask == (uint64_t(1) << 36) - 1)
            return true;

        uint64_t key = (mask << 9) | uint64_t(used);
        if (failed.contains(key))
            return false;

        int firstEmpty = 0;
        while (mask >> firstEmpty & 1)
            ++firstEmpty;
        int tx = firstEmpty % 6, ty = firstEmpty / 6;

        for (int t = 0; t < 9; ++t)
            if (!(used >> t & 1))
            {
                int sId = tiles[t] - 1;
                char L = char('A' + t);

                for (int o = 0; o < 4; ++o)
                {
                    auto &cells = shapes[sId][o];
                    for (auto anchor : cells)
                    {
                        int dx = tx - anchor.first, dy = ty - anchor.second;
                        uint64_t bits = 0;
                        bool ok = true;
                        for (auto c : cells)
                        {
                            int x = dx + c.first, y = dy + c.second;
                            if (x < 0 || x >= 6 || y < 0 || y >= 6)
                            {
                                ok = false;
                                break;
                            }
                            int pos = y * 6 + x;
                            if (mask >> pos & 1)
                            {
                                ok = false;
                                break;
                            }
                            bits |= uint64_t(1) << pos;
                        }
                        if (!ok)
                            continue;
                        uint64_t nMask = mask | bits;
                        if (!holesOk(nMask))
                            continue;

                        for (auto c : cells)
                            grid[dy + c.second][dx + c.first] = L;
                        answer.push_back({t, dx, dy, o});

                        if (dfs(nMask, used | (1 << t)))
                            return true;

                        for (auto c : cells)
                            grid[dy + c.second][dx + c.first] = '.';
                        answer.pop_back();
                    }
                }
            }
        failed.insert(key);
        return false;
    }

    /* ---------- public helpers ------------------------------------------- */
    bool solve() { return dfs(0, 0); }

    vector<string> board() const
    {
        vector<string> out;
        for (int y = 0; y < 6; ++y)
        {
            string row;
            for (int x = 0; x < 6; ++x)
                row.push_back(grid[y][x]);
            out.push_back(move(row));
        }
        return out;
    }
};

/* helper exposed to the unit tests */
std::vector<std::string> chambersSolve(const std::vector<int> &t, bool &ok)
{
    Solver s(t);
    ok = s.solve();
    return ok ? s.board() : std::vector<std::string>{};
}

/* --------------------------- command-line UI ---------------------------- */
#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N))
        return 0;

    for (int i = 1; i <= N; ++i)
    {
        vector<int> v(9);
        for (int &x : v)
            cin >> x;

        cout << "Data Set " << i << "\n";
        Solver solver(v);

        if (solver.solve())
        {
            cout << "The floor may be tiled.\n";
            for (auto &row : solver.board())
                cout << row << "\n";
        }
        else
        {
            cout << "The floor may not be tiled.\n";
        }
        cout << "\n";
    }
    cout << "End of Output\n";
    return 0;
}
#endif
