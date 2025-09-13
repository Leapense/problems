#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    const int MAXT = 200000;
    vector<vector<int>> vec(MAXT + 1);
    vector<long long> ans(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int t;
            cin >> t;
            vec[t].push_back(i);
        }
    }

    vector<int> head(MAXT + 1, 0);

    for (int j = 0; j < M; ++j) {
        int t;
        cin >> t;
        auto &v = vec[t];
        int &h = head[t];
        if (h < (int)v.size()) {
            int i = v[h++];
            ans[i] += 1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (i > 1) cout << ' ';
        cout << ans[i];
    }

    cout << '\n';
    return 0;
}