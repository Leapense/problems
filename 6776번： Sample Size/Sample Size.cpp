#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M;
    cin >> M;

    vector<int> percentages(M);
    unordered_set<int> unique_P;
    for(int i=0; i<M; ++i){
        cin >> percentages[i];
        unique_P.insert(percentages[i]);
    }

    for(int N=1; N<=100000; ++N){
        bool valid = true;
        for(auto P : unique_P){
            if(P <0 || P >100){
                valid = false;
                break;
            }
            if(P ==0){
                continue;
            }
            else if(P ==100){
                long long numerator = 199LL * N + 199;
                long long k_low = numerator / 200;
                long long k_high = N;
                if(k_low > k_high){
                    valid = false;
                    break;
                }
            }
            else{
                long long k_low = ((2LL * P -1) * N + 199) / 200;
                long long k_high = ((2LL * P +1) * N ) / 200;
                if(k_low > k_high){
                    valid = false;
                    break;
                }
            }
        }
        if(valid){
            cout << N << "\n";
            return 0;
        }
    }
    return 0;
}