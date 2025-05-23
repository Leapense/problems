#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> final(N);
    for(auto &x: final) cin >> x;
    
    vector<int> current(N);
    for(int i=0;i<N;i++) current[i] = i+1;
    
    vector<pair<int, int>> operations;
    
    for(int i=0;i<N;i++){
        if(current[i] == final[i]) continue;
        // Determine search order based on the sign of final[i]
        bool prefer_neg = (final[i] > 0);
        int target = prefer_neg ? -final[i] : final[i];
        int j = -1;
        // First, try to find the preferred target
        for(int k=i; k<N; k++){
            if(current[k] == target){
                j = k;
                break;
            }
        }
        // If preferred target not found, find the alternative
        if(j == -1){
            target = prefer_neg ? final[i] : -final[i];
            for(int k=i; k<N; k++){
                if(current[k] == target){
                    j = k;
                    break;
                }
            }
        }
        // Perform rotation if found
        if(j != -1){
            operations.emplace_back(i+1, j+1);
            // Reverse and negate the subarray
            reverse(current.begin()+i, current.begin()+j+1);
            for(int k=i; k<=j; k++) current[k] = -current[k];
        }
        // After rotation, check if the sign is correct
        if(current[i] != final[i]){
            // Need to flip this single element
            operations.emplace_back(i+1, i+1);
            current[i] = -current[i];
        }
    }
    
    // Output
    cout << operations.size() << "\n";
    for(auto &[a, b]: operations){
        cout << a << " " << b << "\n";
    }
}
