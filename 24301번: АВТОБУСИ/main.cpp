//=====================================================================
//   24301번:    АВТОБУСИ                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/24301  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull lcm_two(ull a, ull b) {
	return (__int128(a) * b) / gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull a, b, c, t, d;
    cin >> a >> b >> c >> t >> d;
    ull lcm_bc = lcm_two(b, c);
    ull lcm_abc = lcm_two(a, lcm_bc);
    ull start_time = (d - 1) * t;
    ull end_time = d * t - 1;
    ull count;
    if(start_time == 0){
        count = end_time / lcm_abc + 1;
    }
    else{
        count = end_time / lcm_abc - (start_time -1) / lcm_abc;
    }
    cout << count;

	return 0;
}
