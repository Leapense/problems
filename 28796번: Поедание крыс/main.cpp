//=====================================================================
//   28796번:    Поедание крыс                   
//   @date:   2024-11-03              
//   @link:   https://www.acmicpc.net/problem/28796  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    long long sum_so_far = 0;
    long long max_diff = LLONG_MIN;
    
    for(int i=0;i<n;i++){
        sum_so_far += a[i];
        // Current Kratos eaten up to this step
        long long current_k_eaten = min((long long)k, (long long)sum_so_far);
        // Difference: 2 * Kratos - sum_so_far
        long long diff = 2 * current_k_eaten - sum_so_far;
        if(diff > max_diff){
            max_diff = diff;
        }
    }
    
    cout << max_diff;
}