#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, n;
    cin >> a >> n;
    
    // 가능한 최대 합은 9 * n
    if(a > 9 * n){
        cout << "-1";
        return 0;
    }
    
    string b = "";
    ll remaining = a;
    
    for(int i = 0; i < n; ++i){
        if(remaining >= 9){
            b += '9';
            remaining -= 9;
        }
        else{
            if(remaining > 0){
                b += ('0' + (char)remaining);
                remaining = 0;
            }
            else{
                b += '0';
            }
        }
    }
    
    cout << b;
}
