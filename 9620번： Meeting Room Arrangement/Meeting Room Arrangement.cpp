#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event
{
    int start, finish;
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<Event> events;
        while (true)
        {
            int s, f;
            cin >> s >> f;
            if (s == 0 && f == 0)
                break;
            events.push_back({s, f});
        }
        sort(events.begin(), events.end(), [](const Event &a, const Event &b)
             { return a.finish < b.finish || (a.finish == b.finish && a.start < b.start); });

        int count = 0;
        int lastFinish = 0;
        for (const auto &e : events)
        {
            if (e.start >= lastFinish)
            {
                count++;
                lastFinish = e.finish;
            }
        }

        cout << count << "\n";
    }

    return 0;
}