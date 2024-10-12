#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int T;
    cin >> T;

    while(T--) {
        int X, Y;
        cin >> X >> Y;

        vector<string> grid(Y);

        int start_x = -1, start_y = -1;
        for (int i = 0; i < Y; i++) {
            cin >> grid[i];
            for (int j = 0; j < X; j++) {
                if (grid[i][j] == 'S') {
                    start_x = j;
                    start_y = i;
                }
            }
        }

        long long steps = 0;
        if (X == 1 || Y == 1) {
            steps = 2LL * (X * Y - 1);
        } else {
            if ((1LL * X * Y) % 2 == 0) {
                steps = 1LL * X * Y;
            } else {
                steps = 1LL * X * Y + 1;
            }
        }
        cout << steps << "\n";
    }

    cout << "LOL\n";

    return 0;
}