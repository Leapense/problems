#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M;
    cin >> M;
    // Read M percentages and store unique P's
    vector<int> percentages(M);
    unordered_set<int> unique_P;
    for(int i=0; i<M; ++i){
        cin >> percentages[i];
        unique_P.insert(percentages[i]);
    }
    
    // Iterate N from 1 upwards to find the minimal N
    // Set an upper limit for N to prevent infinite loop
    // Given the rounding rules, N up to 10000 should suffice
    // Adjust if necessary based on constraints
    for(int N=1; N<=100000; ++N){
        bool valid = true;
        for(auto P : unique_P){
            if(P <0 || P >100){
                // Invalid percentage, skip or mark as error
                valid = false;
                break;
            }
            if(P ==0){
                // For P=0, k must be 0
                // This is always possible as k=0 is allowed
                // No additional checks needed
                continue;
            }
            else if(P ==100){
                // For P=100, k must be >= ceil(199*N /200) and <=N
                // Implement ceil(a/b) = (a + b -1)/b
                long long numerator = 199LL * N + 199;
                long long k_low = numerator / 200;
                long long k_high = N;
                if(k_low > k_high){
                    valid = false;
                    break;
                }
            }
            else{
                // For 1 <= P <=99
                // k_low = ceil( (2P -1)*N /200 ) = ((2P -1)*N +199)/200
                // k_high = floor( (2P +1)*N /200 )
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
    // If no N found within the range, although problem guarantees a solution
    return 0;
}