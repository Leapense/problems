#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int w_max = 100000;
    const double pi = acos(-1.0);

    // 미리 계산을 위한 리스트 초기화
    vector<vector<double>> list(w_max +1, vector<double>());

    // 모든 가능한 (x, y)에 대해 w = x^2 + y^2 계산
    for(int x=0; x <= floor(sqrt(w_max)); x++){
        for(int y=0; y <= floor(sqrt(w_max - x*x)); y++){
            int w = x*x + y*y;
            if(w > w_max || w ==0) continue;

            if(x ==0 && y ==0){
                // w=0인 경우는 제외 (문제에서 w >=1)
                continue;
            }
            else if(x ==0){
                // x=0인 경우 y의 부호만 다름
                double angle1 = atan2((double)y, 0.0);
                if(angle1 <0) angle1 += 2 * pi;
                list[w].push_back(angle1);
                
                double angle2 = atan2((double)(-y), 0.0);
                if(angle2 <0) angle2 += 2 * pi;
                list[w].push_back(angle2);
            }
            else if(y ==0){
                // y=0인 경우 x의 부호만 다름
                double angle1 = atan2(0.0, (double)x);
                if(angle1 <0) angle1 += 2 * pi;
                list[w].push_back(angle1);
                
                double angle2 = atan2(0.0, (double)(-x));
                if(angle2 <0) angle2 += 2 * pi;
                list[w].push_back(angle2);
            }
            else{
                // x !=0 그리고 y !=0인 경우 4개의 사분면
                double angle1 = atan2((double)y, (double)x);
                if(angle1 <0) angle1 += 2 * pi;
                double angle2 = atan2((double)y, (double)(-x));
                if(angle2 <0) angle2 += 2 * pi;
                double angle3 = atan2((double)(-y), (double)x);
                if(angle3 <0) angle3 += 2 * pi;
                double angle4 = atan2((double)(-y), (double)(-x));
                if(angle4 <0) angle4 += 2 * pi;
                list[w].push_back(angle1);
                list[w].push_back(angle2);
                list[w].push_back(angle3);
                list[w].push_back(angle4);
            }
        }
    }

    // 각 w에 대해 각도를 정렬
    for(int w=1; w <=w_max; w++) {
        if(!list[w].empty()){
            sort(list[w].begin(), list[w].end());
        }
    }

    // 쿼리 처리
    int Q;
    cin >> Q;
    while(Q--){
        int x1, y1, x2, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;

        if(w > w_max || list[w].empty()){
            cout << "0\n";
            continue;
        }

        // (x1, y1)과 (x2, y2)의 각도 계산
        double angle1 = atan2((double)y1, (double)x1);
        if(angle1 <0) angle1 += 2 * pi;
        double angle2 = atan2((double)y2, (double)x2);
        if(angle2 <0) angle2 += 2 * pi;

        int cnt =0;
        if(angle1 >= angle2){
            // [angle2, angle1] 범위 내의 점들 카운트
            int upper = upper_bound(list[w].begin(), list[w].end(), angle1) - list[w].begin();
            int lower = lower_bound(list[w].begin(), list[w].end(), angle2) - list[w].begin();
            cnt = upper - lower;
        }
        else{
            // [0, angle1]과 [angle2, 2pi) 범위 내의 점들 카운트
            int upper1 = upper_bound(list[w].begin(), list[w].end(), angle1) - list[w].begin();
            int lower2 = lower_bound(list[w].begin(), list[w].end(), angle2) - list[w].begin();
            cnt = upper1 + (int)(list[w].end() - list[w].begin()) - lower2;
        }
        cout << cnt << "\n";
    }
}