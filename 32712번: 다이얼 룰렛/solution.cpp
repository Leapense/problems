// ----------  solution.cpp  ----------
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

long long solve(istream &in, ostream &out)
{
    int N;
    int64 K;
    if (!(in >> N >> K))
        return 0;
    vector<int64> A(N);
    for (auto &x : A)
        in >> x;

    /* prefix & suffix sums */
    vector<int64> pref(N + 1, 0), suff(N + 1, 0);
    for (int i = 0; i < N; ++i)
        pref[i + 1] = pref[i] + A[i];
    for (int i = N - 1; i >= 0; --i)
        suff[i] = suff[i + 1] + A[i];

    int64 best = 0;
    for (int i = 0; i < N; ++i)
    {
        int64 dist = i + 1; // CCW
        if (dist <= K)
            best = max(best, pref[dist] + (K - dist) * A[i]);
        dist = N - i; // CW
        if (dist <= K)
            best = max(best, suff[i] + (K - dist) * A[i]);
    }
    out << best << '\n';
    return best; // (return value is handy in tests)
}

#ifndef UNIT_TEST // <<< only on the judge
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif