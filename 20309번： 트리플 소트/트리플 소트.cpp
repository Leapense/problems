#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (auto &x : A) cin >> x;

    vector<int> pos(N + 1);
    for (int i = 0; i < N; i++) pos[A[i]] = i;
    for (int i = 0; i < N - 2; i++) {
        if (A[i] == i + 1) continue;
        int x = i + 1;
        int j = pos[x];
        if (j < i + 2) {
            cout << "NO";
            return 0;
        }

        while (j > i + 1) {
            int k = j - 2;
            reverse(A.begin() + k, A.begin() + k + 3);
            pos[A[k]] = k;
            pos[A[k+1]] = k+1;
            pos[A[k+2]] = k+2;
            j -= 2;
        }
    }

    if (A[N-2] == N-1 && A[N-1] == N) cout << "YES";
    else cout << "NO";

    return 0;
}