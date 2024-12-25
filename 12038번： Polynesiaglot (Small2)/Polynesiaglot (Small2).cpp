#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int C, V, L;
        cin >> C >> V >> L;
        
        // 이전 단계의 값만 저장
        long long prev_vowel = V; // dp[i-1][0]
        long long prev_consonant = 0; // dp[i-1][1]
        
        for (int i = 2; i <= L; ++i) {
            long long current_vowel = (prev_vowel * V + prev_consonant * V) % MOD;
            long long current_consonant = (prev_vowel * C) % MOD;
            
            // 이전 단계 값 업데이트
            prev_vowel = current_vowel;
            prev_consonant = current_consonant;
        }
        
        long long result = (prev_vowel + prev_consonant) % MOD;
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}