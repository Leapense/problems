#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> skills(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> skills[i];
        }
        
        int min_diff = INT_MAX;
        
        if (N == 8) {
            // 모든 가능한 4명의 조합을 탐색
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    for (int k = j + 1; k < N; ++k) {
                        for (int l = k + 1; l < N; ++l) {
                            int sumA = skills[i] + skills[j] + skills[k] + skills[l];
                            int sumB = 0;
                            
                            // 나머지 4명의 스킬 합 계산
                            for (int m = 0; m < N; ++m) {
                                if (m != i && m != j && m != k && m != l) {
                                    sumB += skills[m];
                                }
                            }
                            
                            // 차이 계산 및 최소 차이 업데이트
                            int diff = abs(sumA - sumB);
                            if (diff < min_diff) {
                                min_diff = diff;
                            }
                        }
                    }
                }
            }
        } else {
            // N이 8이 아닌 경우, 팀을 나눌 수 없으므로 차이는 두 스킬의 차이
            if (N == 2) {
                min_diff = abs(skills[0] - skills[1]);
            } else {
                // 그 외의 경우는 문제 조건에 따라 처리 (예: N=0 또는 N=1 등)
                min_diff = 0;
            }
        }
        
        cout << "Case #" << t << ": " << min_diff << endl;
    }
    
    return 0;
}