#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, b;
    cin >> k >> b;
    int hx, hy;
    cin >> hx >> hy;
    int sx = 1, sy = b;
    while(sx < k && sx <= 1000){
        vector<pair<int, int>> moves = {
            {sx+1, sy}, {sx+1, sy+1}, {sx+1, sy-1},
            {sx, sy+1}, {sx, sy-1},
            {sx-1, sy}, {sx-1, sy+1}, {sx-1, sy-1}
        };
        pair<int, int> chosen_move = {-1, -1};
        for(auto &[nx, ny] : moves){
            if(nx <1 || nx >k || ny <1 || ny >k) continue;
            if(abs(nx - hx) != abs(ny - hy)){
                chosen_move = {nx, ny};
                break;
            }
        }
        if(chosen_move.first == -1){
            for(auto &[nx, ny] : moves){
                if(nx <1 || nx >k || ny <1 || ny >k) continue;
                chosen_move = {nx, ny};
                break;
            }
        }
        if(chosen_move.first == -1){
            break;
        }
        cout << chosen_move.first << " " << chosen_move.second << "\n";
        cout.flush();
        sx = chosen_move.first;
        sy = chosen_move.second;
        if(!(cin >> hx >> hy)){
            break;
        }
        if(sx == hx && sy == hy){
            break;
        }
        if(sx == k && hx != k){
            break;
        }
    }
    return 0;
}