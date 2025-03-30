#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;
using ll = long long;

vector<ll> solveQuadrant(ll A, ll B) {
    vector<ll> res;
    if (A <= 0 || B <= 0) { return res; }
    ll total = A * B;
    ll obstacles = min(A, B);
    ll freeCells = total - obstacles;

    if (A == 1 || B == 1) {
        if (freeCells > 0) res.push_back(freeCells);
        return res;
    }

    ll comp1 = 0, comp2 = 0;
    if (A <= B) {
        comp1 = A * B - A * (A + 1) / 2;
    } else {
        comp1 = A * B - B * (B + 1) / 2;
    }
    comp2 = freeCells - comp1;

    res.push_back(comp1);
    res.push_back(comp2);
    return res;
}

vector<ll> solveTestCase(ll n, ll m, ll x, ll y) {
    vector<ll> regions;

    ll A1 = x - 1, B1 = y - 1;
    ll A2 = x - 1, B2 = m - y;
    ll A3 = n - x, B3 = y - 1;
    ll A4 = n - x, B4 = m - y;

    vector<ll> tmp;
    vector<ll> q1 = solveQuadrant(A1, B1);
    vector<ll> q2 = solveQuadrant(A2, B2);
    vector<ll> q3 = solveQuadrant(A3, B3);
    vector<ll> q4 = solveQuadrant(A4, B4);

    regions.insert(regions.end(), q1.begin(), q1.end());
    regions.insert(regions.end(), q2.begin(), q2.end());
    regions.insert(regions.end(), q3.begin(), q3.end());
    regions.insert(regions.end(), q4.begin(), q4.end());

    if (regions.empty()) {
        return {0};
    }

    sort(regions.begin(), regions.end());
    vector<ll> ans;
    ans.push_back(regions.size());
    for (auto r : regions) ans.push_back(r);

    return ans;
}

#ifndef UNIT_TESTS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<ll> result = solveTestCase(n, m, x, y);
        for (auto val : result) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
#endif
