#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> k(N);
    for(auto &x:k) cin >> x;
    
    // Compute prefix sums
    vector<long long> prefix(N, 0);
    prefix[0] = k[0];
    for(int i=1;i<N;i++) prefix[i] = prefix[i-1] + k[i];
    
    // Read queries
    vector<long long> queries(Q);
    for(auto &x:queries) cin >> x;
    
    for(auto p: queries){
        long long target = p +1;
        // Binary search for first day where prefix[j] >= target
        int day = -1;
        int left =0, right = N-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(prefix[mid] >= target){
                day = mid +1; // days are 1-indexed
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }
        if(day == -1){
            cout << "-1\n";
        }
        else{
            cout << day << "\n";
        }
    }
}
