#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }
    vector<pair<int, int>> requests;

    requests.reserve(N);

    int a;
    long long b;
    long long maxRow = 1;

    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        requests.emplace_back(a, static_cast<int>(b));
        maxRow = max(maxRow, static_cast<long long>(a));
    }

    const long long M = maxRow;
    const long long baseTime = 2LL * (M - 1);

    long long worst = baseTime;
    for (auto const &p : requests)
    {
        long long row = p.first;
        long long release = p.second;
        long long t1 = release + (baseTime - (row - 1));
        long long t2 = release + (row - 1);
        long long finishAt = max(baseTime, min(t1, t2));
        worst = max(worst, finishAt);
    }

    cout << worst << "\n";

    return 0;
}