#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<string> matrix(N);
        for (auto &s : matrix) cin >> s;

        vector<int> rightmost(N, 0);
        for (int i = 0; i < N; i++) {
            int pos = 0;
            for (int j = 0; j < N; j++) if (matrix[i][j] == '1') pos = j + 1;
            rightmost[i] = pos;
        }
        
        int swaps = 0;

        for (int i = 0; i < N; i++) {
            int j = i;
            while (j < N && rightmost[j] > i + 1) j++;

            for (int k = j; k > i; k--) {
                swap(rightmost[k], rightmost[k - 1]);
                swaps++;
            }
        }

        printf("Case #%d: %d\n", tc, swaps);
    }

    return 0;
}