#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    
    const int64 INF = 1000000000000000000LL;
    int64 L = -INF, R = INF;

    bool paradox = false;
    bool gotit = false;
    int paradox_at = -1;
    int gotit_at = -1;

    for (int i = 1; i <= Q; i++) {
        int64 x;
        char c;
        cin >> x >> c;

        if (c == '^') {
            L = max(L, x + 1);
        } else {
            R = min(R, x - 1);
        }

        if (!paradox && L > R) {
            paradox = true;
            paradox_at = i;
        }

        if (!paradox && !gotit && L == R) {
            gotit = true;
            gotit_at = i;
        }
    }

    if (paradox) {
        cout << "Paradox!\n" << paradox_at << "\n";
    } else if (gotit) {
        cout << "I got it!\n" << gotit_at << "\n";
    } else {
        cout << "Hmm...\n";
    }

    return 0;
}
