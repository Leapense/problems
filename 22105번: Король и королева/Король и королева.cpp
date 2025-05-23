#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;
using ll = long long;

struct Region {
    ll size;
};

struct QuadrantResult {
    int count;
    vector<ll> sizes;
};

QuadrantResult solveQuadrant(ll A, ll B) {
    QuadrantResult res;
    if (A == 0 || B == 0) {
        res.count = 0;
        return res;
    }

    ll tot = A * B;
    ll obstacles = min(A, B);
    ll freeCells = tot - obstacles;

    if (A == 1 || B == 1) {
        if (freeCells > 0) {
            res.count = 1;
            res.sizes.push_back(freeCells);
        } else {
            res.count = 0;
        }

        return res;
    }

    ll comp1, comp2;
    if (A <= B) {
        comp1 = A * B - A * (A + 1) / 2;
    } else {
        comp1 = B * (B - 1) / 2;
    }

    comp2 = freeCells - comp1;
    res.count = 2;
    res.sizes.push_back(comp1);
    res.sizes.push_back(comp2);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;

        ll A1 = x - 1, B1 = y - 1;
        ll A2 = x - 1, B2 = m - y;
        ll A3 = n - x, B3 = y - 1;
        ll A4 = n - x, B4 = m - y;

        vector<ll> regions;

        QuadrantResult q1 = solveQuadrant(A1, B1);
        QuadrantResult q2 = solveQuadrant(A2, B2);
        QuadrantResult q3 = solveQuadrant(A3, B3);
        QuadrantResult q4 = solveQuadrant(A4, B4);

        for (auto r : q1.sizes) regions.push_back(r);
        for (auto r : q2.sizes) regions.push_back(r);
        for (auto r : q3.sizes) regions.push_back(r);
        for (auto r : q4.sizes) regions.push_back(r);

        if (regions.empty()) {
            cout << 0 << "\n";
        } else {
            sort(regions.begin(), regions.end());
            cout << regions.size();
            for (auto r : regions) cout << " " << r;
            cout << "\n";
        }
    }

    return 0;
}
