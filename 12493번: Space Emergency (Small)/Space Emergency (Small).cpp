#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        ll L, t, N, C;
        cin >> L >> t >> N >> C;

        vector<ll> a(C);

        for (auto &x : a) cin >> x;

        vector<ll> distances;

        for (int i = 0; i < N; i++) distances.push_back(a[i % C]);

        vector<ll> t_start_list;

        ll current_time = 0;

        for (auto d : distances) {
            t_start_list.push_back(current_time);
            current_time += 2 * d;
        }

        vector<ll> time_saved;

        for (int i = 0; i < N; i++) {
            ll t_start = t_start_list[i];
            ll d = distances[i];

            if (t_start >= t) {
                time_saved.push_back(d);
            }
            else if (t_start + 2 * d <= t) {
                // time_saved.push_back(0);
            }
            else {
                ll saved = d - (t - t_start) / 2;
                if (saved > 0) time_saved.push_back(saved);
            }
        }

        sort(time_saved.begin(), time_saved.end(), greater<ll>());

        ll total_saved = 0;

        for (int i = 0; i < min((ll)L, (ll)time_saved.size()); i++) {
            total_saved += time_saved[i];
        }

        ll total_time = 0;
        for (auto d : distances) total_time += 2 * d;

        total_time -= total_saved;

        cout << "Case #" << tc << ": " << total_time << "\n";
    }

    return 0;
}