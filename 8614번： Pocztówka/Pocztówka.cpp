#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll total = ((ll)n * (n+1)) / 2;
    ll bad = 0;
    ll current = 0;
    for(ll i=0;i<n;i++){
        ll h;
        cin >> h;
        if(h < m){
            current +=1;
        }
        else{
            bad += (current * (current +1))/2;
            current =0;
        }
    }
    bad += (current * (current +1))/2;
    ll answer = total - bad;
    cout << answer;
}