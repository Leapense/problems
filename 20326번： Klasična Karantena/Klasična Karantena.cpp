#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    vector<int> pi(n);
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        size_t dot = s.find('.');
        int left = stoi(s.substr(0, dot));
        int right = stoi(s.substr(dot+1, 2));
        pi[i] = left * 100 + right;
    }
    vector<int> pi_min = pi;
    sort(pi_min.begin(), pi_min.end(), greater<int>());
    ll mask_min = a, total_min = a + b;
    for(auto p: pi_min){
        if(total_min ==0){
            mask_min +=1;
            total_min +=1;
        }
        else{
            if(mask_min * 10000 >= (ll)p * total_min){
                mask_min +=1;
            }
            total_min +=1;
        }
    }
    vector<int> pi_max = pi;
    sort(pi_max.begin(), pi_max.end());
    ll mask_max = a, total_max = a + b;
    for(auto p: pi_max){
        if(total_max ==0){
            mask_max +=1;
            total_max +=1;
        }
        else{
            if(mask_max * 10000 >= (ll)p * total_max){
                mask_max +=1;
            }
            total_max +=1;
        }
    }
    cout << mask_min << " " << mask_max;
}