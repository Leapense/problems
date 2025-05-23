#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Event
{
    ll time;
    int type;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        vector<Event> events;
        events.reserve(2 * N);

        for (int i = 0; i < N; i++)
        {
            ll l, r;
            cin >> l >> r;
            events.push_back({l, 0});
            events.push_back({r, 1});
        }

        sort(events.begin(), events.end(), [](const Event &a, const Event &b)
             {
            if (a.time == b.time) return a.type < b.type;
            return a.time < b.time; });

        ll active = 0, fights = 0;
        for (auto &e : events)
        {
            if (e.type == 0)
            {
                fights += active;
                active++;
            }
            else
            {
                active--;
            }
        }

        cout << "Case " << t << ": " << fights;
        if (t < T)
            cout << "\n";
    }

    return 0;
}