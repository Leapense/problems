#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxEvenSubsequence(const vector<int> &S, int K) {
    int N = S.size();
    int ans = 0;
    int left = 0, oddCount = 0;

    for (int right = 0; right < N; right++) {
        if (S[right] % 2 == 1) {
            oddCount++;
        }

        while (oddCount > K) {
            if (S[left] % 2 == 1) {
                oddCount--;
            }
            left++;
        }

        int evenCount = (right - left + 1) - oddCount;
        ans = max(ans, evenCount);
    }

    return ans;
}

#ifndef UNIT_TESTS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    cout << getMaxEvenSubsequence(S, K) << "\n";
    return 0;
}
#endif
