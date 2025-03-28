#ifndef MAIN_H
#define MAIN_H

#include <vector>
using ll = long long;

struct Segment
{
    ll l;
    ll r;
};

ll solve(ll n, int k, const std::vector<Segment> &segments);

#endif