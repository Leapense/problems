#include <bits/stdc++.h>
using namespace std;

static const int NEVER_REMOVED = INT_MAX;

int getRemovalRound(long long p, long long q) {
    unordered_set<long long> seen;
    seen.reserve(q);
    seen.max_load_factor(0.7f);

    for (int roundNum = 1; roundNum <= q; roundNum++) {
        long long X = (3LL * p) / q;
        long long R = (3LL * p) % q;

        if (X == 1) {
            return roundNum;
        }

        if (R == 0) {
            if ((X % 3) != 0) {
                return roundNum;
            }
        }
        
        p = R;
        if (seen.find(p) != seen.end()) {
            return NEVER_REMOVED;
        }

        seen.insert(p);
    }

    return NEVER_REMOVED;
}

long long gcdLL(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<string> inputStrs(N);

        struct NumInfo {
            string s;
            int roundRemoved;
            long long p, q;
        };

        vector<NumInfo> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> inputStrs[i];
        }

        for (int i = 0; i < N; i++) {
            const string &s = inputStrs[i];

            assert(s.size() >= 2 && s[0] == '0' && s[1] == '.');
            string digits = s.substr(2);

            long long p = stoll(digits);
            long long q = 1;

            for (int k = 0; k < (int)digits.size(); k++) {
                q *= 10LL;
            }

            long long g = gcdLL(p, q);
            p /= g;
            q /= g;

            int rr = getRemovalRound(p, q);
            arr[i] = {s, rr, p, q};
        }

        auto cmp = [&](const NumInfo &a, const NumInfo &b) {
            if (a.roundRemoved != b.roundRemoved) {
                return a.roundRemoved < b.roundRemoved;
            }

            __int128 lhs = ((__int128)a.p) * b.q;
            __int128 rhs = ((__int128)b.p) * a.q;

            return lhs < rhs;
        };

        sort(arr.begin(), arr.end(), cmp);

        cout << "Case #" << tc << ":\n";
        for (auto &x : arr) {
            cout << x.s << "\n";
        }
    }

    return 0;
}