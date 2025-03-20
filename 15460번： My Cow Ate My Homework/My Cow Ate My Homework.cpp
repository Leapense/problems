#include <iostream>
#include <vector>
#include <limits>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> scores(N);
    for (int i = 0; i < N; i++)
        cin >> scores[i];

    vector<ll> suff_sum(N + 1, 0);
    vector<int> suff_min(N);

    suff_sum[N] = 0;
    suff_min[N - 1] = scores[N - 1];

    for (int i = N - 1; i >= 0; i--)
    {
        suff_sum[i] = suff_sum[i + 1] + scores[i];
        if (i < N - 1)
            suff_min[i] = min(scores[i], suff_min[i + 1]);
    }

    double best = -1e18;
    vector<int> ans;

    for (int K = 1; K <= N - 2; K++)
    {
        int cnt = N - K;
        if (cnt < 2)
            continue;

        ll total = suff_sum[K];
        int m = suff_min[K];

        double avg = (double)(total - m) / (cnt - 1);
        if (avg > best)
        {
            best = avg;
            ans.clear();

            ans.push_back(K);
        }
        else if (avg == best)
        {
            ans.push_back(K);
        }
    }

    for (auto k : ans)
    {
        cout << k << "\n";
    }

    return 0;
}