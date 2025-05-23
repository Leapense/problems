#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    string new_s = s;

    for (int iter = 0; iter < K; iter++) {
        for (int p = 0; p < N; p++) {
            char left = s[(p + N - 1) % N];
            char current = s[p];
            char right = s[(p + 1) % N];

            if ((left == current && current == right) || (left != current && left != right && current != right)) {
                new_s[p] = 'B';
            } else {
                char X, Y;
                if (left == current) {
                    X = left;
                    Y = right;
                } else if (left == right) {
                    X = left;
                    Y = current;
                } else {
                    X = current;
                    Y = left;
                }

                if ((X == 'R' && Y == 'G') || (X == 'G' && Y == 'B') || (X == 'B' && Y == 'R')) {
                    new_s[p] = 'R';
                } else {
                    new_s[p] = 'G';
                }
            }
        }

        s = new_s;
    }

    int cntR = 0, cntG = 0, cntB = 0;

    for (char c : s) {
        if (c == 'R') cntR++;
        else if (c == 'G') cntG++;
        else if (c == 'B') cntB++;
    }

    cout << cntR << " " << cntG << " " << cntB;

    return 0;
}