#include <iostream>
#include <vector>
#include <algorithm>
#include "main.h"

using namespace std;

int maxContinuousBlocks(int N, int K, const vector<int>& L) {
    int start = 0, count = 0, ans = 1;
    for (int end = 0; end < N - 1; end++) {
        if (L[end] > K) {
            count++;
        }

        while (count > 1 && start <= end) {
            if (L[start] > K) count--;
            start++;
        }

        ans = max(ans, end - start + 2);
    }

    return ans;
}

#ifndef UNIT_TESTS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> L(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> L[i];
    }

    cout << maxContinuousBlocks(N, K, L) << "\n";

    return 0;
}
#endif
