//=====================================================================
//   27640번:    Brain fold (Easy)                   
//   @date:   2024-10-30              
//   @link:   https://www.acmicpc.net/problem/27640  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Constants
const int MOD = 1e9 + 7;
const int MAX = 100005;

// Precompute powers of 2 modulo MOD
ll power_of_two[MAX];

// Function to precompute powers of two
void precompute_powers() {
    power_of_two[0] = 1;
    for(int i = 1; i < MAX; ++i){
        power_of_two[i] = (power_of_two[i-1] * 2) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precompute_powers();
    
    int t;
    cin >> t;
    while(t--){
        // Read a blank line before each test case
        // Since the first test case might not have a blank line, handle accordingly
        // We'll read until we get a number
        // But since constraints are tight, we assume proper formatting
        
        int n;
        cin >> n;
        
        string folds;
        cin >> folds;
        
        string cut;
        cin >> cut;
        
        // Count horizontal and vertical folds
        int h = 0, v = 0;
        for(char c : folds){
            if(c == 'T' || c == 'B') h++;
            else if(c == 'L' || c == 'R') v++;
        }
        
        // Determine the cut direction
        // If cut contains 'T' or 'B', it's horizontal
        // If cut contains 'L' or 'R', it's vertical
        bool is_horizontal = false, is_vertical = false;
        for(char c : cut){
            if(c == 'T' || c == 'B') { is_horizontal = true; }
            if(c == 'L' || c == 'R') { is_vertical = true; }
        }
        
        ll result = 0;
        if(is_horizontal){
            // Number of pieces = 2^v +1
            if(v >= MAX){
                // Compute on the fly
                ll res = 1;
                for(int i=0;i<v;i++) res = (res * 2) % MOD;
                result = (res + 1) % MOD;
            }
            else{
                result = (power_of_two[v] + 1) % MOD;
            }
        }
        else if(is_vertical){
            // Number of pieces = 2^h +1
            if(h >= MAX){
                // Compute on the fly
                ll res = 1;
                for(int i=0;i<h;i++) res = (res * 2) % MOD;
                result = (res + 1) % MOD;
            }
            else{
                result = (power_of_two[h] + 1) % MOD;
            }
        }
        // Output the result
        cout << result << "\n";
    }
}
