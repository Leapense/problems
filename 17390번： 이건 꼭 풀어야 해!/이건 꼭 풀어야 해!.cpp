#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;

    cin >> N >> Q;

    vector<int> A(N);
    for (auto &x : A) {
        cin >> x;
    }

    sort(A.begin(), A.end());

    vector<int> S(N + 1);

    S[0] = 0;
    for (int i = 1; i <= N; ++i) {
        S[i] = S[i - 1] + A[i - 1];
    }

    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;

        int sum = S[R] - S[L - 1];
        cout << sum << "\n";
    }

    return 0;
}