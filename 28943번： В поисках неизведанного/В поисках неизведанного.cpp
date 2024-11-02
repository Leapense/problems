#pragma GCC optimize("O3")
#define FAST_IO cin.tie(0) -> sync_with_stdio(0); cin.exceptions(ios::badbit | ios::failbit);

#include <bits/stdc++.h>

using namespace std;

int main()
{
    FAST_IO;
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
    } else if (n == 2) {
        int k, neighbor;
        bool connected = false;

        for (int i = 0; i < 2; ++i) {
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> neighbor;

                if ((i == 0 && neighbor == 2) || (i == 1 && neighbor == 1)) {
                    connected = true;
                }
            }
        }

        cout << (connected ? 1 : 0) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}