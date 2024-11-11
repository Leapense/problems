#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<int> A(N);
    for(auto &x:A) cin >> x;
    ll sum_internal =0;
    for(auto x:A){
        sum_internal += (ll)(x-2)*180;
    }
    ll sum_nesting = 360LL * (N-1);
    ll total = sum_internal + sum_nesting;
    cout << total;
}