#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> correct(N+1);
    for(int i=1;i<=N;i++) cin >> correct[i];
    vector<bool> S(N+1, false);
    for(int i=0;i<M;i++){
        int x;
        cin >> x;
        S[x] = true;
    }
    // Initialize allowed_mask
    vector<int> allowed_mask(N+1, 0);
    for(int i=1;i<=N;i++){
        if(S[i]){
            allowed_mask[i] = (1 << (correct[i]-1));
        }
        else{
            allowed_mask[i] = (~(1 << (correct[i]-1))) & 31; // Only keep the first 5 bits
        }
    }
    // Initialize possible_mask
    vector<int> possible_mask(N+2, 31); // Initialize with all choices possible at position N+1
    for(int i=N;i>=1;i--){
        int temp =0;
        for(int c=1;c<=5;c++){
            if(allowed_mask[i] & (1 << (c-1))){
                // Ensure there's at least one choice in possible_mask[i+1] for the next position
                // Since Yunee must choose a different answer from the previous one,
                // we need to make sure that possible_mask[i+1] has at least one choice different from c
                if( possible_mask[i+1] & (~(1 << (c-1))) ){
                    temp |= (1 << (c-1));
                }
            }
        }
        possible_mask[i] = temp;
    }
    // Check if possible_mask[1] is non-zero, otherwise no valid sequence exists
    if(possible_mask[1] == 0){
        cout << "-1\n";
        return 0;
    }
    // Assign A
    vector<int> A(N+1, 0);
    for(int i=1;i<=N;i++){
        bool found = false;
        for(int c=1;c<=5;c++){
            if( (possible_mask[i] & (1 << (c-1))) && (i ==1 || c != A[i-1]) ){
                A[i] = c;
                found = true;
                break;
            }
        }
        if(!found){
            cout << "-1\n";
            return 0;
        }
    }
    // Output
    for(int i=1;i<=N;i++){
        if(i >1) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
}
