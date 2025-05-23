#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    string s;
    cin >> s;

    vector<int> count(10, 0);
    long long sum = 0;

    for (char c : s)
    {
        int d = c - '0';
        count[d]++;
        sum += d;
    }

    int rem = sum % 3;
    auto removeDigits = [&](int toRemove, const vector<int> &group) -> bool
    {
        for (int d : group)
        {
            while (toRemove > 0 && count[d] > 0)
            {
                count[d]--;
                toRemove--;
                if (toRemove == 0)
                    return true;
            }
        }

        return (toRemove == 0);
    };

    bool possible = true;
    if (rem == 1)
    {
        if (!removeDigits(1, {1, 4, 7}))
        {
            if (!removeDigits(2, {2, 5, 8}))
            {
                possible = false;
            }
        }
    }
    else if (rem == 2)
    {
        if (!removeDigits(1, {2, 5, 8}))
        {
            if (!removeDigits(2, {1, 4, 7}))
            {
                possible = false;
            }
        }
    }

    if (!possible)
    {
        cout << -1;
        return 0;
    }

    string result;

    for (int d = 9; d >= 0; d--)
    {
        result.append(count[d], char('0' + d));
    }

    if (result.empty())
    {
        cout << 0;
    }
    else
    {
        cout << result;
    }

    return 0;
}