#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int normalize(int degree) {
    degree %= 360;
    if (degree < 0) degree += 360;
    return degree;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    ll k;
    cin >> k;

    string commands;
    cin >> commands;

    int direction_old = 0;
    int direction_new = 0;
    ll punishments = 0;

    bool need_check = (m > 0) and (n - m > 0);

    for (char cmd : commands) {
        if (cmd == 'L') {
            direction_old += 90;
            direction_new -= 90;
        } else if (cmd == 'R') {
            direction_old -= 90;
            direction_new += 90;
        } else if (cmd == 'A') {
            direction_old += 180;
            direction_new += 180;
        }

        direction_old = normalize(direction_old);
        direction_new = normalize(direction_new);

        if (need_check and direction_old != direction_new) {
            punishments++;
        }
    }

    cout << punishments << "\n";

    return 0;
}