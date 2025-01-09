#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    
    cin >> N;
    vector<int> A(N);

    for (auto &x : A) cin >> x;

    int maxA = *max_element(A.begin(), A.end());
    int minA = *min_element(A.begin(), A.end());

    if (maxA == minA) {
        cout << 1;
        return 0;
    }

    int last_max = -1, last_min = -1;
    int res = N;
    for (int i = 0; i < N; i++) {
        if (A[i] == maxA) last_max = i;
        if (A[i] == minA) last_min = i;

        if (last_max != -1 && last_min != -1) {
            res = min(res, abs(last_max - last_min) + 1);
        }
    }

    cout << res << "\n";

    return 0;
}