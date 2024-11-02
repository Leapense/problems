//=====================================================================
//   20458번:    Автоматизированное управление доставкой                   
//   @date:   2024-10-15              
//   @link:   https://www.acmicpc.net/problem/20458  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k, x, y;
    cin >> k >> x >> y;
    ll z = x + k -1;
    // Compute a = ceil(y / z)
    ll a = (y + z -1) / z;
    // Compute y' = max(y, a *x)
    ll y_prime = max(y, a *x);
    cout << y_prime;
}
