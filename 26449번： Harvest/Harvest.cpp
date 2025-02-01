#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> plants(N);

    for (int i = 0; i < N; i++)
    {
        cin >> plants[i].first >> plants[i].second;
    }

    int K;
    cin >> K;

    vector<int> h(K);

    for (int i = 0; i < K; i++)
    {
        cin >> h[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(h.begin(), h.end(), plants[i].first);
        if (it != h.end() && *it <= plants[i].second)
            ans++;
    }

    cout << ans << "\n";
    return 0;
}