#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, N;
    cin >> H >> W;
    cin >> N;
    vector<pair<int, int>> stickers(N);
    for(auto &p: stickers) cin >> p.first >> p.second;
    int max_area = 0;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            for(int rot1=0; rot1<2; rot1++) {
                int r1 = rot1 ? stickers[i].second : stickers[i].first;
                int c1 = rot1 ? stickers[i].first : stickers[i].second;
                if(r1 > H || c1 > W) continue;
                for(int rot2=0; rot2<2; rot2++) {
                    int r2 = rot2 ? stickers[j].second : stickers[j].first;
                    int c2 = rot2 ? stickers[j].first : stickers[j].second;
                    if(r2 > H || c2 > W) continue;
                    // 가로로 배치
                    if(r1 + r2 <= H && max(c1, c2) <= W){
                        max_area = max(max_area, r1*c1 + r2*c2);
                    }
                    // 세로로 배치
                    if(c1 + c2 <= W && max(r1, r2) <= H){
                        max_area = max(max_area, r1*c1 + r2*c2);
                    }
                }
            }
        }
    }
    cout << max_area;
}