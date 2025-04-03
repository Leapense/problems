#include "main.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

ll computeCost (int coord, const vector<int>& L, const vector<ll>& prefixL, const vector<int>& R, const vector<ll>& prefixR) {
    auto itL = upper_bound(L.begin(), L.end(), coord);
    int countL = L.end() - itL;
    int idx = itL - L.begin();
    ll sumL = (countL > 0) ? (prefixL.back() - (idx == 0 ? 0LL : prefixL[idx - 1])) : 0LL;
    ll costL = sumL - (ll)countL * coord;

    auto itR = lower_bound(R.begin(), R.end(), coord);
    int countR = itR - R.begin();
    ll sumR = (countR > 0) ? prefixR[countR - 1] : 0LL;
    ll costR = (ll)countR * coord - sumR;

    return costL + costR;
}

void solve(istream &in, ostream &out) {
    int T;
    in >> T;
    for (int t = 1; t <= T; t++) {
        int K;
        in >> K;
        vector<tuple<int, int, int, int>> rects(K);
        vector<int> Lx, Rx, Ly, Ry;

        for (int i = 0; i < K; i++) {
            int x1, y1, x2, y2;
            in >> x1 >> y1 >> x2 >> y2;
            rects[i] = {x1, y1, x2, y2};
            Lx.push_back(x1);
            Ly.push_back(y1);
            Rx.push_back(x2);
            Ry.push_back(y2);
        }

        sort(Lx.begin(), Lx.end());
        sort(Ly.begin(), Ly.end());
        sort(Rx.begin(), Rx.end());
        sort(Ry.begin(), Ry.end());

        vector<ll> prefixLx(Lx.size()), prefixRx(Rx.size());
        prefixLx[0] = Lx[0];
        for (size_t i = 1; i < Lx.size(); i++) {
            prefixLx[i] =  prefixLx[i - 1] + Lx[i];
        }
        prefixRx[0] = Rx[0];
        for (size_t i = 1; i < Rx.size(); i++) {
            prefixRx[i] = prefixRx[i - 1] + Rx[i];
        }

        vector<ll> prefixLy(Ly.size()), prefixRy(Ry.size());
        prefixLy[0] = Ly[0];
        for (size_t i = 1; i < Ly.size(); i++) {
            prefixLy[i] = prefixRy[i - 1] + Ry[i];
        }

        set<int> candX;
        for (int x : Lx) candX.insert(x);
        for (int x : Rx) candX.insert(x);

        int bestX = *candX.begin();
        ll minCostX = computeCost(bestX, Lx, prefixLx, Rx, prefixRx);
        for (int x : candX) {
            ll cost = computeCost(x, Lx, prefixLx, Rx, prefixRx);
            if (cost < minCostX || (cost == minCostX && x < bestX)) {
                bestX = x;
                minCostX = cost;
            }
        }

        set<int> candY;
        for (int y : Ly) candY.insert(y);
        for (int y : Ry) candY.insert(y);

        int bestY = *candY.begin();
        ll minCostY = computeCost(bestY, Ly, prefixLy, Ry, prefixRy);
        for (int y : candY) {
            ll cost = computeCost(y, Ly, prefixLy, Ry, prefixRy);
            if (cost < minCostY || (cost == minCostY && y < bestY)) {
                bestY = y;
                minCostY = cost;
            }
        }

        out << "Case #" << t << ": " << bestX << " " << bestY << "\n";
    }
}

#ifndef UNIT_TESTS
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
