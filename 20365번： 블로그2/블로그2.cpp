#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string S;
    cin >> S;

    int R = 0, B = 0;
    char prev = 0;

    for (char c : S) {
        if (c != prev) {
            if (c == 'R') R++;
            else B++;
            prev = c;
        }
    }

    cout << 1 + min(R, B);

    return 0;
}