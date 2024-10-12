#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, x, y;
    cin >> n >> m;
    cin >> x >> y;
    
    // 방향: 0 - 오른쪽, 1 - 아래, 2 - 왼쪽, 3 - 위
    // dx, dy 배열
    ll dirs[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
    
    ll cx = x;
    ll cy = y;
    int dir = 0; // 시작 방향: 오른쪽
    ll s =1;
    ll total_steps =0;
    
    while(1){
        for(int i=0;i<2;i++){
            ll steps_to_boundary;
            if(dir ==0){
                steps_to_boundary = n - cx;
            }
            else if(dir ==1){
                steps_to_boundary = cy -1;
            }
            else if(dir ==2){
                steps_to_boundary = cx -1;
            }
            else { // dir ==3
                steps_to_boundary = m - cy;
            }
            
            ll steps_possible = steps_to_boundary;
            if(steps_possible >= s){
                // 이동 가능
                total_steps += s;
                cx += dirs[dir][0]*s;
                cy += dirs[dir][1]*s;
            }
            else{
                // 이동 불가능, 가능한 만큼만 이동
                total_steps += steps_possible;
                // 최종 방문한 셀 수는 시작 셀 + total_steps
                cout << total_steps +1;
                return 0;
            }
            // 오른쪽으로 회전
            dir = (dir +1) %4;
        }
        s +=1;
    }
    
    // 모든 이동이 가능할 경우
    cout << (total_steps +1);
}
