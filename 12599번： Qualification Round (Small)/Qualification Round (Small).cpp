#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++){
        int P, C; cin >> P >> C;
        vector<long long> S(P);
        long long sumS = 0;
        for(int i=0; i<P; i++){
            cin >> S[i];
            sumS += S[i];
        }
        long long left = 0, right = sumS;
        while(left < right){
            long long mid = (left + right + 1) / 2;
            long long cap = 0;
            for(int i=0; i<P; i++){
                cap += min((long long)S[i], mid);
            }
            if(cap >= mid * C) left = mid; 
            else right = mid - 1;
        }
        cout << "Case #" << tc << ": " << left << "\n";
    }
    return 0;
}