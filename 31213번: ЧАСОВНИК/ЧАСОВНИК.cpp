#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, m;
    cin >> h >> m;
    
    // 현재 시침의 각도
    double hour_angle = h * 30.0 + m * 0.5;
    // 분침의 각도 (고정)
    double minute_angle = m * 6.0;
    
    // 시침이 분침의 각도로 도달하는데 필요한 시간 t (분)
    // 시침은 0.5도/분
    // t = (minute_angle - hour_angle) / 0.5
    double t_double = (minute_angle - hour_angle) / 0.5;
    
    // t를 정수로 변환 (반올림)
    // 그러나 실제로는 정확히 일치해야 하므로 소수점 오류를 고려
    // t가 음수이면 720을 더함
    int t = round(t_double);
    while(t <=0){
        t += 720;
    }
    t = t % 720;
    if(t ==0) t =720;
    
    // 초기 시간에 t 분을 더함
    int initial_total_minutes = h * 60 + m;
    int new_total_minutes = initial_total_minutes + t;
    new_total_minutes %= 720; // 12시간 단위
    if(new_total_minutes ==0) new_total_minutes =720;
    int new_h = (new_total_minutes / 60);
    if(new_h ==0) new_h =12;
    int new_m = new_total_minutes % 60;
    
    // 경과 시간 t를 시와 분으로
    int elapsed_h = t / 60;
    int elapsed_m = t % 60;
    
    cout << new_h << " " << new_m << "\n";
    cout << elapsed_h << " " << elapsed_m;
}