#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<pair<ll, ll>> trees(N);
        for (int i = 0; i < N; i++)
        {
            cin >> trees[i].first >> trees[i].second;
        }

        vector<ll> vertPaths, horzPaths;
        vertPaths.reserve(M);
        horzPaths.reserve(M);

        for (int i = 0; i < M; i++)
        {
            string s;
            cin >> s;

            if (s[0] == 'x')
            {
                ll a = stoll(s.substr(2));
                vertPaths.push_back(a);
            }
            else
            {
                ll b = stoll(s.substr(2));
                horzPaths.push_back(b);
            }
        }

        sort(vertPaths.begin(), vertPaths.end());
        vertPaths.erase(unique(vertPaths.begin(), vertPaths.end()), vertPaths.end());
        sort(horzPaths.begin(), horzPaths.end());
        horzPaths.erase(unique(horzPaths.begin(), horzPaths.end()), horzPaths.end());

        unordered_map<ll, vector<int>> rows, cols;
        rows.reserve(N);
        cols.reserve(N);
        for (int i = 0; i < N; i++)
        {
            auto [x, y] = trees[i];
            rows[y].push_back(i);
            cols[x].push_back(i);
        }

        const ll INF = LLONG_MAX;
        vector<ll> L(N), R(N), D(N), U(N);

        for (auto &kv : rows)
        {
            auto &idxs = kv.second;
            vector<pair<ll, int>> vx;
            vx.reserve(idxs.size());
            for (int i : idxs)
            {
                vx.emplace_back(trees[i].first, i);
            }
            sort(vx.begin(), vx.end());
            int K = vx.size();
            for (int j = 0; j < K; j++)
            {
                int idx = vx[j].second;
                L[idx] = (j > 0 ? vx[j - 1].first : LLONG_MIN);
                R[idx] = (j + 1 < K ? vx[j + 1].first : INF);
            }
        }

        for (auto &kv : cols)
        {
            auto &idxs = kv.second;
            vector<pair<ll, int>> vy;
            vy.reserve(idxs.size());
            for (int i : idxs)
            {
                vy.emplace_back(trees[i].second, i);
            }
            sort(vy.begin(), vy.end());
            int K = vy.size();
            for (int j = 0; j < K; j++)
            {
                int idx = vy[j].second;
                D[idx] = (j > 0 ? vy[j - 1].first : LLONG_MIN);
                U[idx] = (j + 1 < K ? vy[j + 1].first : INF);
            }
        }

        vector<char> visible(N, 0);

        for (int i = 0; i < N; i++)
        {
            auto [x, y] = trees[i];
            {
                auto it = upper_bound(vertPaths.begin(), vertPaths.end(), L[i]);
                if (it != vertPaths.end() && *it < x)
                    visible[i] = 1;
            }
            {
                auto it = upper_bound(vertPaths.begin(), vertPaths.end(), x);
                if (it != vertPaths.end() && *it < R[i])
                    visible[i] = 1;
            }
            {
                auto it = upper_bound(horzPaths.begin(), horzPaths.end(), D[i]);
                if (it != horzPaths.end() && *it < y)
                    visible[i] = 1;
            }
            {
                auto it = upper_bound(horzPaths.begin(), horzPaths.end(), y);
                if (it != horzPaths.end() && *it < U[i])
                    visible[i] = 1;
            }
        }

        int answer = accumulate(visible.begin(), visible.end(), 0);
        cout << answer << "\n";
    }

    return 0;
}