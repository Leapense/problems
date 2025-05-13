#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    
    vector<int> len(N);
    for (int &x : len) cin >> x;
    
    sort(len.begin(), len.end());
    long long ans = 0;
    int L = 0;
    int R = N - 1;
    
    while (R > L) {
        ++ans;
        if (len[L] == 1) {
            ++L; --R;
        } else {
            --len[L];
            --R;
            
            if (len[L] == 0) ++L;
        }
    }
    
    cout << ans << "\n";
    return 0;
}