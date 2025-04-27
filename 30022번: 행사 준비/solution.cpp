#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve(istream &in, ostream &out)
{
    int N, A, B;
    in >> N >> A >> B;

    vector<i64> d(N);
    i64 sumq = 0;

    for (int i = 0; i < N; i++)
    {
        i64 p, q;
        in >> p >> q;

        sumq += q;
        d[i] = p - q;
    }
    nth_element(d.begin(), d.begin() + A, d.end());
    i64 extra = 0;
    for (int i = 0; i < A; i++)
    {
        extra += d[i];
    }

    out << sumq + extra << "\n";
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve(cin, cout);
    return 0;
}
#endif