#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    while(T--) {
        int F, R, N;
        cin >> F >> R >> N;

        vector<vector<int>> floors(F +  1);
        for (int i = 0; i < N; i++) {
            int a, b; cin >> a >> b;
            floors[a].push_back(b);
        }

        for (int i = 1; i <= F; i++) sort(floors[i].begin(), floors[i].end());

        long long total_horizontal_cost = 0;

        for (int f = 1; f <= F; f++) {
            const auto &offices = floors[f];
            if (offices.empty()) {
                continue;
            }

            int k = (int)offices.size();
            int min_off = offices.front();
            int max_off = offices.back();

            long long best = LLONG_MAX;

            best = min(best, (long long)2 * max_off);

            best = min(best, (long long)2 * ((R + 1) - min_off));

            for (int j = 1; j < k; j++) {
                int max_up = offices[j - 1];
                int min_down = offices[j];
                long long cost_split = 2LL * max_up + 2LL * ((R + 1) - min_down);
                if (cost_split < best) best = cost_split;
            }

            total_horizontal_cost += best;
        }

        long long fixed_cost = 2LL * (F - 1) + (R + 3);

        cout << (total_horizontal_cost + fixed_cost) << "\n";
    }

    return 0;
}