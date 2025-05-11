#include <bits/stdc++.h>
using namespace std;

int countOvertake(const vector<string> &entry, const vector<string> &exitv)
{
    int n = entry.size();
    unordered_set<string> exited;

    int pos = 0, ans = 0;
    for (const auto &car : exitv)
    {
        if (car != entry[pos])
            ++ans;
        exited.insert(car);
        while (pos < n && exited.count(entry[pos]))
            ++pos;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<string> in(n), out(n);

    for (auto &s : in)
        cin >> s;
    for (auto &s : out)
        cin >> s;

    cout << countOvertake(in, out) << "\n";
    return 0;
}