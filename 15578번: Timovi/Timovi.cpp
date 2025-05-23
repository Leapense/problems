#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K, M;

    cin >> N >> K >> M;

    vector<ll> teams(N, 0);
    ll full = M / K, rem = M % K;

    auto cycleLen = 2LL * (N - 1);
    auto getCycleTeam = [&](ll pos) -> int
    {
        if (pos < N - 1)
            return int(N - pos - 2);
        else
            return int(pos - (N - 1) + 1);
    };
    auto getOverallTeam = [&](ll idx) -> int
    {
        if (idx < N)
            return int(idx);
        ll pos = (idx - N) % cycleLen;
        return getCycleTeam(pos);
    };

    if (full < N)
    {
        for (int i = 0; i < full; i++)
        {
            teams[i]++;
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            teams[i]++;
        }

        ll R = full - N;
        ll cycles = R / cycleLen;

        ll r = R % cycleLen;
        teams[0] += cycles;
        teams[N - 1] += cycles;

        for (int i = 1; i < N - 1; i++)
        {
            teams[i] += 2 * cycles;
        }

        for (ll j = 0; j < r; j++)
        {
            int pos = getCycleTeam(j);
            teams[pos]++;
        }
    }

    if (rem > 0)
    {
        int pos = getOverallTeam(full);
        teams[pos]--;
        teams[pos] += 1;
        ll base = teams[pos];
        teams[pos] = base * K + rem;
    }

    for (int i = 0; i < N; i++)
    {
        if (rem > 0 && i == getOverallTeam(full))
            continue;
        teams[i] *= K;
    }
    for (int i = 0; i < N; i++)
    {
        cout << teams[i] << (i == N - 1 ? "\n" : " ");
    }
    return 0;
}