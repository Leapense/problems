#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ld = long double;

struct Recurrence
{
    ld A{0}, B{0};
    bool constant{false};
};

static Recurrence buildRec(i64 s0, i64 s1, i64 s2, i64 s3)
{
    Recurrence R{};

    if (s0 == s1 && s1 == s2 && s2 == s3)
    {
        R.constant = true;
        return R;
    }

    i64 det = s1 * 1LL * s1 - s0 * 1LL * s2;

    if (det != 0)
    {
        R.A = static_cast<ld>(s2 * 1LL * s1 - s0 * 1LL * s3) / det;
        R.B = static_cast<ld>(s1 * 1LL * s3 - s2 * 1LL * s2) / det;
    }
    else
    {
        ld r = 0.0;
        if (s1 != 0)        r = static_cast<ld>(s2) / s1;
        else if (s2 != 0)   r = static_cast<ld>(s3) / s2;
        else                r = 0.0L;
        R.A = r;
        R.B = 0.0;
    }

    return R;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        int D, P;
        if (!(ss >> D >> P)) continue;

        vector<i64> S;
        i64 val;
        while (ss >> val) S.push_back(val);

        bool recurrenceNeeded = (int)S.size() < D + 1;

        Recurrence R;
        if (recurrenceNeeded) {
            R = buildRec(S[0], S[1], S[2], S[3]);
        }

        auto tooFast = [&](i64 v) { return v > P; };

        int lastSafeIdx     = -1;
        bool doomed         = false;
        bool mayFallBlind   = false;

        int idx = 0;
        for (; idx < (int)S.size() && idx <= D; ++idx)
        {
            if (tooFast(S[idx]))
            {
                doomed = (idx == 0);
                break;
            }

            lastSafeIdx = idx;
        }

        i64 prev2 = S.size() >= 2 ? S[S.size() - 2] : 0;
        i64 prev1 = S.size() >= 1 ? S[S.size() - 1] : 0;

        while (!doomed && idx <= D) {
            if (idx < (int)S.size()) { ++idx; continue; }

            i64 next;
            if (R.constant) next = prev1;
            else {
                ld nxt = R.A * prev1 + R.B * prev2;
                next = llround(nxt);
            }

            if (tooFast(next)) {
                doomed = (idx == 0);
                break;
            }

            lastSafeIdx = idx;
            ++idx;
            prev2 = prev1;
            prev1 = next;
        }

        if (!doomed) {
            if (idx <= D) {

            } else {
                if (!recurrenceNeeded) {
                    if (S[D] <= P) mayFallBlind = true;
                } else {
                    if (prev1 <= P) mayFallBlind = true;
                }
            }
        }

        if (doomed) {
            cout << "The spider is going to fall!\n";
        } else if (mayFallBlind) {
            cout << "The spider may fall!\n";
        } else {
            cout << (D - lastSafeIdx) << "\n";
        }
    }

    return 0;
}