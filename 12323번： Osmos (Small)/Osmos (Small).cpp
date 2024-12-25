#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int A, vector<int>& motes) {
    sort(motes.begin(), motes.end());
    int minOperations = motes.size(); // 최악의 경우: 모든 mote를 제거
    int operations = 0;
    
    for (size_t i = 0; i < motes.size(); ++i) {
        if (A > motes[i]) {
            A += motes[i];
        } else {
            // 현재 mote를 흡수할 수 없을 때
            // 새로운 mote를 추가하거나 기존 mote를 제거
            if (A == 1) {
                // Armin의 mote가 1이면 더 이상 커질 수 없으므로 모든 남은 mote를 제거
                operations += motes.size() - i;
                break;
            }
            while (A <= motes[i]) {
                A += A - 1;
                operations++;
            }
            A += motes[i];
        }
        // 현재까지의 연산 횟수와 남은 mote를 제거하는 경우를 비교
        minOperations = min(minOperations, operations + (int)(motes.size() - i - 1));
    }
    
    return minOperations;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int A, N;
        cin >> A >> N;
        vector<int> motes(N);
        for (int i = 0; i < N; ++i) {
            cin >> motes[i];
        }
        int result = solve(A, motes);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}