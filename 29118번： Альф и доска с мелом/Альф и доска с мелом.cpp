#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    if(k ==0){
        cout << n;
        return 0;
    }
    
    ll x = n;
    ll step =0;
    ll total_sum =0;
    // Map from last digit to pair(step, sum_so_far)
    // To detect cycles
    unordered_map<int, pair<ll, ll>> mp;
    
    while(step <k){
        int d = x %10;
        if(mp.find(d) != mp.end()){
            ll previous_step = mp[d].first;
            ll previous_sum = mp[d].second;
            ll cycle_length = step - previous_step;
            ll cycle_sum = total_sum - previous_sum;
            if(cycle_length ==0){
                // Avoid infinite loop
                break;
            }
            ll remaining_steps = k - step;
            ll cycles = remaining_steps / cycle_length;
            total_sum += cycles * cycle_sum;
            step += cycles * cycle_length;
        }
        else{
            mp[d] = {step, total_sum};
        }
        if(step >=k){
            break;
        }
        int d_current = x %10;
        total_sum += d_current;
        x += d_current;
        step +=1;
    }
    // If any remaining steps
    while(step <k){
        int d_current = x %10;
        total_sum += d_current;
        x += d_current;
        step +=1;
    }
    ll result = n + total_sum;
    cout << result;
}