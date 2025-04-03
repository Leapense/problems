#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
using ll = long long;

// 주어진 좌표 coord에 대해 1차원 비용 F(coord)를 계산하는 함수
ll computeCost(int coord, const vector<int>& L, const vector<ll>& prefixL,
               const vector<int>& R, const vector<ll>& prefixR) {
    // L: 각 직사각형의 좌측 경계 (정렬되어 있음)
    // R: 각 직사각형의 우측 경계 (정렬되어 있음)
    // 비용 = sum_{L_i > coord} (L_i - coord) + sum_{R_i < coord} (coord - R_i)
    
    // L_i > coord 인 경우
    auto itL = upper_bound(L.begin(), L.end(), coord);
    int countL = L.end() - itL;
    int idx = itL - L.begin();
    ll sumL = (countL > 0) ? (prefixL.back() - (idx == 0 ? 0LL : prefixL[idx - 1])) : 0LL;
    ll costL = sumL - (ll)countL * coord;
    
    // R_i < coord 인 경우
    auto itR = lower_bound(R.begin(), R.end(), coord);
    int countR = itR - R.begin();
    ll sumR = (countR > 0) ? prefixR[countR - 1] : 0LL;
    ll costR = (ll)countR * coord - sumR;
    
    return costL + costR;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        int K;
        cin >> K;
        vector<tuple<int,int,int,int>> rects(K);
        vector<int> Lx, Rx, Ly, Ry;
        for (int i = 0; i < K; i++){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            rects[i] = {x1, y1, x2, y2};
            Lx.push_back(x1);
            Rx.push_back(x2);
            Ly.push_back(y1);
            Ry.push_back(y2);
        }
        
        // 정렬 및 prefix sum 계산
        sort(Lx.begin(), Lx.end());
        sort(Rx.begin(), Rx.end());
        sort(Ly.begin(), Ly.end());
        sort(Ry.begin(), Ry.end());
        
        vector<ll> prefixLx(Lx.size()), prefixRx(Rx.size());
        prefixLx[0] = Lx[0];
        for (size_t i = 1; i < Lx.size(); i++){
            prefixLx[i] = prefixLx[i - 1] + Lx[i];
        }
        prefixRx[0] = Rx[0];
        for (size_t i = 1; i < Rx.size(); i++){
            prefixRx[i] = prefixRx[i - 1] + Rx[i];
        }
        
        vector<ll> prefixLy(Ly.size()), prefixRy(Ry.size());
        prefixLy[0] = Ly[0];
        for (size_t i = 1; i < Ly.size(); i++){
            prefixLy[i] = prefixLy[i - 1] + Ly[i];
        }
        prefixRy[0] = Ry[0];
        for (size_t i = 1; i < Ry.size(); i++){
            prefixRy[i] = prefixRy[i - 1] + Ry[i];
        }
        
        // 후보 좌표: Lx와 Rx의 경계값을 중복 제거하여 set에 저장
        set<int> candX;
        for (int x : Lx) candX.insert(x);
        for (int x : Rx) candX.insert(x);
        
        // 최적 x 값 찾기 (비용 최소, 동률이면 작은 x 선택)
        int bestX = *candX.begin();
        ll minCostX = computeCost(bestX, Lx, prefixLx, Rx, prefixRx);
        for (int x : candX) {
            ll cost = computeCost(x, Lx, prefixLx, Rx, prefixRx);
            if (cost < minCostX || (cost == minCostX && x < bestX)) {
                bestX = x;
                minCostX = cost;
            }
        }
        
        // 후보 좌표: Ly와 Ry의 경계값을 중복 제거하여 set에 저장
        set<int> candY;
        for (int y : Ly) candY.insert(y);
        for (int y : Ry) candY.insert(y);
        
        // 최적 y 값 찾기
        int bestY = *candY.begin();
        ll minCostY = computeCost(bestY, Ly, prefixLy, Ry, prefixRy);
        for (int y : candY) {
            ll cost = computeCost(y, Ly, prefixLy, Ry, prefixRy);
            if (cost < minCostY || (cost == minCostY && y < bestY)) {
                bestY = y;
                minCostY = cost;
            }
        }
        
        cout << "Case #" << t << ": " << bestX << " " << bestY << "\n";
    }
    
    return 0;
}

