#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    vector<int> pos(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        pos[A[i]] = i;
    }

    bool possible = true;
    for (int i = 1; i <= N - 2; i++) {
        if (A[i] == i) continue;

        int current_pos = pos[i];
        while (current_pos > i) {
            if (current_pos - 2 < i) {
                possible = false;
                break;
            }

            int k = current_pos - 2;
            swap(A[k], A[k + 2]);
            swap(A[k + 1], A[k + 2]);

            pos[A[k]] = k;
            pos[A[k + 1]] = k + 1;
            pos[A[k + 2]] = k + 2;
            current_pos -= 2;
        }

        if (!possible) break;
    }

    if (possible) {
        if (A[N - 1] == N - 1 && A[N] == N) {
            cout << "YES";
            return 0;
        }

        if (N >= 3 && A[N - 2] == N - 2 && A[N - 1] == N && A[N] == N - 1) {
            swap(A[N - 2], A[N]);
            swap(A[N - 2], A[N]);
            swap(A[N - 1], A[N]);

            if (A[N - 2] == N - 2 && A[N - 1] == N - 1 && A[N] == N) {
                cout << "YES";
                return 0;
            }
        }

        cout << "NO";
    }

    else cout << "NO";

    return 0;
}