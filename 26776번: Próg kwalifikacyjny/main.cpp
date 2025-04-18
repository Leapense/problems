// qualifier.cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> V(N);
    for(int i = 0; i < N; i++) cin >> V[i];
    sort(V.begin(), V.end(), greater<>());
    vector<long long> prefix(N);
    prefix[0] = V[0];
    for(int i = 1; i < N; i++) prefix[i] = prefix[i-1] + V[i];
    int Q;
    cin >> Q;
    while(Q--){
        long long P;
        cin >> P;
        int idx = lower_bound(prefix.begin(), prefix.end(), P) - prefix.begin();
        cout << (idx + 1) << "\n";
    }
    return 0;
}

