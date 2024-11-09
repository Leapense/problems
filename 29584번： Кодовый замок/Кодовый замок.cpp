#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    string s;
    cin >> s;
    vector<int> d(n);
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9') d[i]=s[i]-'0';
        else d[i]=s[i]-'A'+10;
    }
    long long total_sum=0;
    for(auto num:d) total_sum += num;
    vector<long long> prefix_sum(n+1,0);
    for(int i=0;i<n;i++) prefix_sum[i+1]=prefix_sum[i]+d[i];
    bool found=false;
    string res;
    for(int i=n-1;i>=0;i--){
        if(d[i]<k-1){
            int new_d_i = d[i]+1;
            long long sum_so_far = prefix_sum[i] + new_d_i;
            long long sum_required = total_sum - sum_so_far;
            if(sum_required >=0 && sum_required <= (long long)(n-i-1)*(k-1)){
                vector<int> d_new(d);
                d_new[i]=new_d_i;
                for(int j=i+1;j<n;j++) d_new[j]=0;
                long long sr = sum_required;
                for(int j=n-1;j>i;j--){
                    d_new[j] = min((int)(k-1), (int)sr);
                    sr -= d_new[j];
                }
                string ans="";
                for(auto num:d_new){
                    if(num <10) ans += char('0' + num);
                    else ans += char('A' + num -10);
                }
                cout << ans;
                return 0;
            }
        }
    }
    cout << "Impossible";
}