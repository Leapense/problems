#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    int offset = 0;
    cin >> N >> Q;
    
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < Q; ++i) {
        int x;
        cin >> x;

        if (x == 1) {
            int a, b;
            cin >> a >> b;
            int actual_index = (offset + a - 1) % N;
            if (actual_index < 0) actual_index += N;
            A[actual_index] += b;
        } else if (x == 2) {
            int a;
            cin >> a;
            a %= N;
            offset = (offset - a) % N;
            if (offset < 0) offset += N;

            //cout << offset << "\n";
        } else if (x == 3) {
            int a;
            cin >> a;
            offset = (offset + a) % N;
        }
    }

    for (int j = 0; j < N; ++j) {
        cout << A[(offset + j) % N] << " ";
    }
    return 0;
}