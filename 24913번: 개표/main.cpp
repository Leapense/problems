#include <bits/stdc++.h>
using namespace std;

struct Fenw
{
    int n;
    vector<long long> fenw;
    Fenw(int n) : n(n), fenw(n + 1, 0) {}
    void update(int i, long long delta)
    {
        for (; i <= n; i += i & -i)
        {
            fenw[i] += delta;
        }
    }
    long long query(int i)
    {
        long long s = 0;
        for (; i > 0; i -= i & -i)
        {
            s += fenw[i];
        }
        return s;
    }
};

struct Event
{
    int type;
    long long x, p_or_y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<Event> events;
    events.reserve(Q);

    for (int i = 0; i < Q; i++)
    {
        int t;
        long long x, p;
        cin >> t >> x >> p;
        events.push_back({t, x, p});
    }

    vector<long long> oppVotes(N + 1, 0);
    vector<long long> compVals;
    compVals.reserve(Q + N + 5);

    for (int i = 1; i <= N; i++)
    {
        compVals.push_back(0);
    }

    for (auto &ev : events)
    {
        if (ev.type == 1)
        {
            int cand = (int)ev.p_or_y;
            if (cand <= N)
            {
                long long newVal = oppVotes[cand] + ev.x;
                oppVotes[cand] = newVal;
                compVals.push_back(newVal);
            }
        }
    }

    sort(compVals.begin(), compVals.end());
    compVals.erase(unique(compVals.begin(), compVals.end()), compVals.end());
    int compSize = compVals.size();

    fill(oppVotes.begin(), oppVotes.end(), 0);

    Fenw fenwCount(compSize), fenwSum(compSize);

    int idx0 = int(lower_bound(compVals.begin(), compVals.end(), 0) - compVals.begin()) + 1;
    for (int i = 1; i <= N; i++)
    {
        fenwCount.update(idx0, 1);
        fenwSum.update(idx0, 0);
    }

    long long myVotes = 0;
    vector<string> answers;
    answers.reserve(Q);

    for (auto &ev : events)
    {
        if (ev.type == 1)
        {
            int cand = (int)ev.p_or_y;
            if (cand == N + 1)
            {
                myVotes += ev.x;
            }
            else
            {
                long long oldVal = oppVotes[cand];
                int oldIdx = int(lower_bound(compVals.begin(), compVals.end(), oldVal) - compVals.begin()) + 1;
                fenwCount.update(oldIdx, -1);
                fenwSum.update(oldIdx, -oldVal);

                long long newVal = oldVal + ev.x;
                oppVotes[cand] = newVal;
                int newIdx = int(lower_bound(compVals.begin(), compVals.end(), newVal) - compVals.begin()) + 1;
                fenwCount.update(newIdx, 1);
                fenwSum.update(newIdx, newVal);
            }
        }
        else
        {
            long long addMy = ev.x, extraOpp = ev.p_or_y;
            long long finalMy = myVotes + addMy;

            if (finalMy <= 0)
            {
                answers.push_back("NO");
                continue;
            }

            long long threshold = finalMy - 1;
            int pos = int(upper_bound(compVals.begin(), compVals.end(), threshold) - compVals.begin());
            long long cnt = 0, sumVal = 0;

            if (pos > 0)
            {
                cnt = fenwCount.query(pos);
                sumVal = fenwSum.query(pos);
            }

            if (fenwCount.query(compSize) - cnt > 0)
            {
                answers.push_back("NO");
                continue;
            }

            long long capacity = cnt * threshold - sumVal;
            if (capacity >= extraOpp)
                answers.push_back("YES");
            else
                answers.push_back("NO");
        }
    }

    for (auto &ans : answers)
    {
        cout << ans << "\n";
    }

    return 0;
}