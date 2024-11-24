#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_M = 1000000;

    vector<int> spf(MAX_M +1, 0);
    for(int i=2; i<=MAX_M; ++i){
        if(spf[i]==0){
            spf[i]=i;
            for(int j=2*i; j<=MAX_M; j+=i){
                if(spf[j]==0){
                    spf[j]=i;
                }
            }
        }
    }

    vector<int> tau(MAX_M + 1, 1);
    tau[0] = 0;
    for (int m = 2; m <= MAX_M; ++m) {
        if (spf[m] == m) {
            tau[m] = 2;
        } else {
            int p = spf[m];
            int cnt = 0;
            int tmp = m;

            while (tmp % p == 0) {
                tmp /= p;
                cnt += 1;
            }
            tau[m] = tau[tmp] * (cnt + 1);
        }
    }

    const int MAX_N = 100;
    vector<int> min_m(MAX_N + 1, 0);

    for (int m = 1; m <= MAX_M; ++m) {
        int tc = tau[m];
        int n_candidate = (tc + 1) / 2;

        if (n_candidate > MAX_N) continue;
        if (min_m[n_candidate] == 0) {
            min_m[n_candidate] = m;
        }
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n >=1 && n <=MAX_N && min_m[n]!=0 && min_m[n] <= MAX_M){
            cout << min_m[n] << "\n";
        }
        else{
            cout << "Too big\n";
        }
    }

    return 0;
}