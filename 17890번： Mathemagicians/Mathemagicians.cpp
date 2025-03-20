#include <bits/stdc++.h>

using namespace std;

// Efficiently checks if desired hat configuration can be achieved.
bool canChangeHats(int n, const string &initial, const string &target)
{
    bool has_same_adjacent = false;

    // Check if the target configuration has at least one pair of adjacent same-colored hats
    for (int i = 0; i < n; ++i)
    {
        if (target[i] == target[(i + 1) % n])
        {
            has_same_adjacent = true;
            break;
        }
    }

    // If target configuration has no adjacent similar colors,
    // initial must already be the target, else it's impossible.
    if (!has_same_adjacent)
        return initial == target;

    // Otherwise, always possible to reach configuration.
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string initial, target;
    cin >> initial >> target;

    cout << (canChangeHats(n, initial, target) ? "yes" : "no") << "\n";

    return 0;
}