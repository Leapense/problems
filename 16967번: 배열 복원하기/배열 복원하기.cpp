#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;

    int BH = H + X;
    int BW = W + Y;

    vector<vector<long long>> B(BH, vector<long long>(BW, 0));
    for (int i = 0; i < BH; i++) {
        for (int j = 0; j < BW; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<long long>> A(H, vector<long long>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i >= X && j >= Y) {
                A[i][j] = B[i][j] - A[i - X][j - Y];
            } else {
                A[i][j] = B[i][j];
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j > 0) cout << ' ';
            cout << A[i][j];
        }

        cout << "\n";
    }

    return 0;
}