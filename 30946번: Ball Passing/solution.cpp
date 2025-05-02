//  Ball Passing – maximise total passing distance
//  C++26, no extra libraries.
//
//  -------------------------------------------------------------
//  Build:
//      g++ -std=c++2b -O2 -pipe -static -s solution.cpp
//
//  -------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct Pt
{
    long double x, y;
};

inline long double dist(const Pt &a, const Pt &b)
{
    long double dx = a.x - b.x, dy = a.y - b.y;
    return sqrtl(dx * dx + dy * dy);
}

long double bestSum(const vector<int> &idx, const vector<Pt> &p)
{
    const int m = static_cast<int>(idx.size());
    if (m == 0)
        return 0.0L;
    const int half = m / 2;
    long double sum = 0.0L;
    for (int i = 0; i < half; ++i)
        sum += dist(p[idx[i]], p[idx[i + half]]);
    return sum;
}

void solve(istream &in, ostream &out)
{
    int N;
    if (!(in >> N))
        return;
    string S;
    in >> S;
    vector<Pt> pt(N);
    for (auto &v : pt)
        in >> v.x >> v.y;

    vector<int> boy, girl;
    for (int i = 0; i < N; ++i)
        (S[i] == 'B' ? boy : girl).push_back(i);

    long double ans = bestSum(boy, pt) + bestSum(girl, pt);

    out << fixed << setprecision(9) << static_cast<double>(ans) << '\n';
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif
