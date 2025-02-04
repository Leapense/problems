#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int forks = n, knives = m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> eventPQ;

    vector<string> ans;

    for (int i = 0; i < k; i++)
    {
        int t, l, a;
        cin >> t >> l >> a;

        while (!eventPQ.empty() && eventPQ.top().first <= t)
        {
            auto ev = eventPQ.top();
            eventPQ.pop();

            if (ev.second == 0)
            {
                forks++;
            }
            else
            {
                forks++;
                knives++;
            }
        }

        if (a == 0)
        {
            if (forks >= 1)
            {
                ans.push_back("Yes");
                forks--;
                eventPQ.push({t + l, 0});
            }
            else
            {
                ans.push_back("No");
            }
        }
        else
        {
            if (forks >= 1 && knives >= 1)
            {
                ans.push_back("Yes");
                forks--;
                knives--;
                eventPQ.push({t + l, 1});
            }
            else
            {
                ans.push_back("No");
            }
        }
    }

    for (const auto &s : ans)
    {
        cout << s << "\n";
    }

    return 0;
}