#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> H(N);
    for (auto &x : H) cin >> x;
    vector<int> left(N,1), right(N,1);
    for(int i=1;i<N;i++) {
        if(H[i] >= H[i-1]) left[i]=left[i-1]+1;
        else left[i]=1;
    }

    for(int i=N-2;i>=0;i--){
        if(H[i] >= H[i+1]) right[i]=right[i+1]+1;
        else right[i]=1;
    }

    int max_width = 0;
    for (int i = 0; i < N; i++) max_width = max(max_width, left[i] + right[i] - 1);
    cout << max_width << "\n";

    return 0;
}