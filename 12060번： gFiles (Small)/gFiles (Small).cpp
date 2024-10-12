#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        int N;
        cin >> N;
        vector<pair<int, int>> updates(N);
        for(int i=0;i<N;i++) cin >> updates[i].first >> updates[i].second;
        
        // Collect all Pi=100 and their Ki
        vector<int> pi100_kis;
        for(auto &[Pi, Ki] : updates){
            if(Pi == 100){
                pi100_kis.push_back(Ki);
            }
        }
        
        bool ambiguous = false;
        int answer = -1;
        
        if(!pi100_kis.empty()){
            // Check if all Ki's for Pi=100 are same
            int k = pi100_kis[0];
            bool all_same = true;
            for(auto ki : pi100_kis){
                if(ki != k){
                    all_same = false;
                    break;
                }
            }
            if(!all_same){
                // Multiple different Ki's for Pi=100, impossible
                answer = -1;
            }
            else{
                // T must be k
                int T_val = k;
                bool valid = true;
                // T must be >= all Ki's
                for(auto &[Pi, Ki] : updates){
                    if(Ki > T_val){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    // Check all updates
                    for(auto &[Pi, Ki] : updates){
                        if(T_val ==0){
                            // Avoid division by zero
                            if(Pi !=0 || Ki !=0){
                                valid = false;
                                break;
                            }
                        }
                        else{
                            // Compute floor((Ki *100)/T_val)
                            int computed_Pi = (Ki * 100) / T_val;
                            if(computed_Pi != Pi){
                                valid = false;
                                break;
                            }
                        }
                    }
                }
                if(valid){
                    answer = T_val;
                }
                else{
                    answer = -1;
                }
            }
        }
        else{
            // No Pi=100, find possible T by range intersection
            int T_min =1, T_max=2000;
            for(auto &[Pi, Ki] : updates){
                if(Pi ==0){
                    // T > Ki *100
                    int current_min = Ki * 100 +1;
                    T_min = max(T_min, current_min);
                    // T_max remains 2000
                }
                else{
                    // Pi <100
                    // T_min_i = floor(Ki*100 / (Pi+1)) +1
                    // T_max_i = floor(Ki*100 / Pi)
                    // Handle Pi !=0
                    if(Pi ==0 && Ki >0){
                        // Already handled above
                    }
                    int T_min_i = (Ki * 100) / (Pi +1) +1;
                    int T_max_i = (Ki * 100) / Pi;
                    T_min = max(T_min, T_min_i);
                    T_max = min(T_max, T_max_i);
                }
            }
            // Now, iterate T from T_min to T_max and check validity
            vector<int> valid_T;
            for(int T_val = T_min; T_val <= T_max && T_val <=2000; T_val++){
                bool valid = true;
                for(auto &[Pi, Ki] : updates){
                    if(T_val ==0){
                        if(!(Pi ==0 && Ki ==0)){
                            valid = false;
                            break;
                        }
                    }
                    else{
                        // Ki should not exceed T_val
                        if(Ki > T_val){
                            valid = false;
                            break;
                        }
                        int computed_Pi = (Ki * 100) / T_val;
                        if(computed_Pi != Pi){
                            valid = false;
                            break;
                        }
                    }
                }
                if(valid){
                    valid_T.push_back(T_val);
                    if(valid_T.size() >1){
                        break; // No need to collect more
                    }
                }
            }
            if(valid_T.size() ==1){
                answer = valid_T[0];
            }
            else{
                answer = -1;
            }
        }
        
        cout << "Case #" << tc << ": " << answer << "\n";
    }
}