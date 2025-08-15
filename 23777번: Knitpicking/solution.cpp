#include <bits/stdc++.h>
using namespace std;

struct Counts {
    long long l = 0;
    long long r = 0;
    long long a = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    unordered_map<string, Counts> mp;
    mp.reserve(static_cast<size_t>(n) * 2);

    for (int i = 0; i < n; i++) {
        string type, fit;
        long long k;
        cin >> type >> fit >> k;
        auto& c = mp[type];
        if (fit == "left") {
            c.l += k;
        } else if (fit == "right") {
            c.r += k;
        } else {
            c.a += k;
        }
    }

    long long safe_without_pair = 0;
    bool pair_exists = false;

    for (const auto& kv : mp) {
        const auto& c = kv.second;
        if ((c.l > 0 && c.r > 0) || (c.a >= 2) || (c.a > 0 && (c.l > 0 || c.r > 0))) {
            pair_exists = true;
        }
        if (c.l + c.r > 0) {
            safe_without_pair += max(c.l, c.r);
        } else if (c.a > 0) {
            safe_without_pair += 1;
        }
    }

    if (!pair_exists) {
        cout << "impossible\n";
    } else {
        cout << (safe_without_pair + 1) << '\n';
    }

    return 0;
}