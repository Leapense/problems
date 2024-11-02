//=====================================================================
//   16179번:    Palapa Number                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/16179  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll powmod_func(ll a, ll b, ll mod){
    ll res = 1;
    a %= mod;
    while(b >0){
        if(b &1){
            res = (res *a) % mod;
        }
        a = (a *a) % mod;
        b >>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        ll power = powmod_func(10, N-4, 9973);
        ll result = (5625 * power) % 9973;
        cout << result << "\n";
    }
}