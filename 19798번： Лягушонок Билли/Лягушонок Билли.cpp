#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> positions(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> positions[i];
    }

    // Group the mosquitoes by their positions.
    // Since positions are sorted in non-decreasing order, we can simply group from the end.
    vector<pair<ll, ll>> groups; // {position, count}
    ll count = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (positions[i] == positions[i + 1])
        {
            ++count;
        }
        else
        {
            groups.push_back({positions[i + 1], count});
            count = 1;
        }
    }
    groups.push_back({positions[0], count});

    // Process groups in descending order (we built groups in descending order already).
    ll shift = 0;
    ll energy = 0;
    for (auto &group : groups)
    {
        ll pos = group.first;
        ll cnt = group.second;
        // Calculate effective position
        ll effectivePos = pos - shift;
        if (effectivePos > 0)
        {
            energy += effectivePos * cnt;
            shift += cnt; // Only mosquitoes eaten with energy cause further shifts.
        }
    }

    cout << energy << "\n";
    return 0;
}