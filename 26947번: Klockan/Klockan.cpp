#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int A;
    cin >> A;

    for (int q = 0; q <= 11; ++q) {
        int temp = A + 300 * q;
        if (temp % 5 != 0) continue;

        int rhs = (temp / 5) % 720;

        int r = (131 * rhs) % 720;

        if (r >= 0 && r <= 59) {
            int t = 60 * q + r;
            int hours = t / 60;
            int minutes = t % 60;
            cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << endl;
            return 0;
        }
    }

    cout << "Invalid angle" << endl;

    return 0;
}