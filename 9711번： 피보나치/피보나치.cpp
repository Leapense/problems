#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int case_num = 1; case_num <= T; ++case_num){
        ll P, Q;
        cin >> P >> Q;
        // Handle edge cases
        if(P == 1 || P ==2){
            ll M = 1 % Q;
            cout << "Case #" << case_num << ": " << M << "\n";
            continue;
        }
        // Initialize first two Fibonacci numbers
        ll a = 1 % Q; // F(1)
        ll b = 1 % Q; // F(2)
        ll c = 0;
        for(int i =3; i <= P; ++i){
            c = (a + b) % Q;
            a = b;
            b = c;
        }
        cout << "Case #" << case_num << ": " << c << "\n";
    }
}