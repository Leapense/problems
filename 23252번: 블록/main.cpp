#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long A, B, C;
        cin >> A >> B >> C;
        // ㄴ자 타일은 반드시 1x1 타일과 짝을 이루어야 하므로 A >= C여야 함
        // 그리고 남은 1x1 타일 (A - C)는 2개씩 모여 한 열을 채워야 하므로 (A - C)가 짝수여야 함
        if(A >= C && (A - C) % 2 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

