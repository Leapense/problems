#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int N, M;
        cin >> N >> M;
        if (!cin || (N == 0 && M == 0))
            break;
        int r;
        cin >> r;

        unordered_map<int, vector<pair<int, int>>> events;
        events.reserve(r * 2);

        for (int i = 0; i < r; i++)
        {
            int t, n, m, s;
            cin >> t >> n >> m >> s;
            events[m].push_back({t, s == 1 ? 1 : -1});
        }

        unordered_map<int, vector<pair<int, int>>> usage;

        usage.reserve(events.size());

        for (auto &kv : events)
        {
            int m = kv.first;
            auto &ev = kv.second;
            sort(ev.begin(), ev.end());

            int countLogin = 0, startTime = -1;
            for (auto &x : ev)
            {
                int time = x.first, delta = x.second;
                if (countLogin == 0 && delta == 1)
                {
                    startTime = time;
                }

                countLogin += delta;

                if (countLogin == 0 && startTime != -1)
                {
                    usage[m].push_back({startTime, time});
                    startTime = -1;
                }
            }
        }

        for (auto &kv : usage)
        {
            auto &intervals = kv.second;
            sort(intervals.begin(), intervals.end());
            vector<pair<int, int>> merged;
            int st = intervals[0].first, en = intervals[0].second;

            for (int i = 1; i < (int)intervals.size(); i++)
            {
                if (intervals[i].first <= en)
                {
                    en = max(en, intervals[i].second);
                }
                else
                {
                    merged.push_back({st, en});
                    st = intervals[i].first;
                    en = intervals[i].second;
                }
            }

            merged.push_back({st, en});
            intervals = merged;
        }

        int q;
        cin >> q;

        while (q--)
        {
            int ts, te, m;
            cin >> ts >> te >> m;
            auto it = usage.find(m);
            if (it == usage.end())
            {
                cout << 0 << "\n";
                continue;
            }

            auto &intervals = it->second;
            int total = 0;
            for (auto &iv : intervals)
            {
                if (iv.second <= ts)
                    continue;
                if (iv.first >= te)
                    break;
                int ss = max(iv.first, ts);
                int ee = min(iv.second, te);
                if (ee > ss)
                    total += (ee - ss);
            }

            cout << total << "\n";
        }
    }
    return 0;
}