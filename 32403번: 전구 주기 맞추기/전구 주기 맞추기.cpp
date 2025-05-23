#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, T;

    cin >> N >> T;

    vector<int> a(N);

    for (auto &x : a) cin >> x;

    vector<int> divisors;

    for (int d = 1; d * d <= T; ++d) {
        if (T % d == 0) {
            divisors.push_back(d);
            if(T / d != d) {
                divisors.push_back(T / d);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    long long total = 0;

    for(int i=0; i<N; ++i){
        int ai = a[i];
        auto it = lower_bound(divisors.begin(), divisors.end(), ai);
        int min_diff = INT32_MAX;
        if(it != divisors.end()){
            min_diff = abs(ai - *it);
        }
        if(it != divisors.begin()){
            it--;
            min_diff = min(min_diff, abs(ai - *it));
        }
        total += min_diff;
    }
    cout << total;
}