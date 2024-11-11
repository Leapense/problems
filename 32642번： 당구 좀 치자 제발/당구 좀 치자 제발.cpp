#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<int> weather(N);
    for(auto &x: weather) cin >> x;
    ll anger = 0;
    ll sum = 0;
    for(int i=0;i<N;i++){
        if(weather[i]==1) anger +=1;
        else anger -=1;
        sum += anger;
    }
    cout << sum;
}