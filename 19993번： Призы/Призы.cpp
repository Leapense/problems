#include <iostream>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    long long x = m - 1;  // 가로로 굴려야 할 횟수
    long long y = n - 1;  // 세로로 굴려야 할 횟수

    // 1) 둘 다 0인 경우(즉 m=1,n=1)
    if(x == 0 && y == 0){
        cout << 0 << endl;
        return 0;
    }

    // 2) x=0 또는 y=0 → 한 축으로만 연속 굴림
    //    => 굴림 횟수 k = x+y 이고, 글자면이 바닥에 닿는 횟수는 floor((k+2)/4).
    if(x == 0){
        cout << (y + 2) / 4 << endl;
        return 0;
    }
    if(y == 0){
        cout << (x + 2) / 4 << endl;
        return 0;
    }

    // 3) 이제 x>0, y>0
    //    (a) min(x,y)=1 → 0번 가능
    //    (b) 그 외(둘 다 2 이상) → 1번
    if(x == 1 || y == 1){
        cout << 0 << endl;
    } else {
        // x>=2, y>=2
        cout << 1 << endl;
    }

    return 0;
}
