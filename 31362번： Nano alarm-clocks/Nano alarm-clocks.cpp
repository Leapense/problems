#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    const ll L = 12LL * 1000000LL * 1000000LL; // Total cycle in seconds: 12 * 1e6 * 1e6 = 12e12
    vector<ll> times(n);
    ll sum_t = 0;
    
    for(int i=0;i<n;i++){
        ll h, m, s;
        cin >> h >> m >> s;
        times[i] = h * 1000000LL * 1000000LL + m * 1000000LL + s;
        sum_t += times[i];
    }
    
    sort(times.begin(), times.end());
    
    // Group the sorted times and count duplicates
    vector<pair<ll, int>> unique_times;
    ll current_time = times[0];
    int count = 1;
    
    for(int i=1;i<n;i++){
        if(times[i] == current_time){
            count++;
        }
        else{
            unique_times.emplace_back(make_pair(current_time, count));
            current_time = times[i];
            count = 1;
        }
    }
    unique_times.emplace_back(make_pair(current_time, count));
    
    ll minimal_sum = LLONG_MAX;
    ll cumulative_j = 0;
    
    for(auto &[t_j, cnt] : unique_times){
        cumulative_j += cnt;
        ll f_T = n * t_j - sum_t + L * (n - cumulative_j);
        if(f_T < minimal_sum){
            minimal_sum = f_T;
        }
    }
    
    // Now, convert minimal_sum back to h, m, s
    ll h = minimal_sum / (1000000LL * 1000000LL);
    minimal_sum %= (1000000LL * 1000000LL);
    ll m = minimal_sum / 1000000LL;
    ll s = minimal_sum % 1000000LL;
    
    cout << h << " " << m << " " << s;
}