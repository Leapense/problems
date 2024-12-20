#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<ll, ll>> bales(N);
    for(int i=0;i<N;i++) cin >> bales[i].first >> bales[i].second;
    sort(bales.begin(), bales.end(), [&](const pair<ll,ll> &a, const pair<ll,ll> &b)->bool{
        return a.second < b.second;
    });
    vector<ll> max_left(N+1, LLONG_MIN);
    for(int i=1;i<=N;i++) {
        max_left[i] = max(max_left[i-1], bales[i-1].second + bales[i-1].first);
    }
    vector<ll> min_right(N+2, LLONG_MAX);
    for(int i=N;i>=1;i--){
        min_right[i] = min(min_right[i+1], bales[i-1].second - bales[i-1].first);
    }
    ll total =0;
    for(int i=1;i<N;i++){
        if(min_right[i+1] <= bales[i-1].second){
            ll start = max(bales[i-1].second, min_right[i+1]);
            ll end = min(bales[i].second, max_left[i]);
            if(end > bales[i-1].second){
                total += end - bales[i-1].second;
            }
        }
    }
    cout << total;
    return 0;
}