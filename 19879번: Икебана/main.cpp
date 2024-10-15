//=====================================================================
//   19879번:    Икебана                   
//   @date:   2024-10-15              
//   @link:   https://www.acmicpc.net/problem/19879  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, h;
    cin >> n >> m >> h;

    bool impossible = false;
    ll count =0;
    bool prev = false;
	
    for(ll i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        ll hi;
        if(m ==1){
            hi = a;
        }
        else{
            if(b ==0){
                hi = a;
            }
            else{
                hi = a + (m-1)*b;
                if(hi < a){
                    hi = LLONG_MAX;
                }
            }
        }
        if(hi < h){
            impossible = true;
        }
        else{
            if(hi > h){
                if(!prev){
                    count++;
                    prev = true;
                }
            }
            else{
                prev = false;
            }
        }
    }
    if(impossible){
        cout << "-1";
    }
    else{
        cout << count;
    }

	return 0;
}
