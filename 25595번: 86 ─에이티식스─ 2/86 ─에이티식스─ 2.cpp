#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int N;
int grid[105][105];

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    cin >> N;
    int sr = -1, sc = -1;
    int parity_s = -1;
    bool hasLegion = false;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int val;
            cin >> val;

            grid[i][j] = val;
            if (val == 2) {
                sr = i;
                sc = j;
                parity_s = (sr + sc) % 2;
            } else if (val == 1) {
                hasLegion = true;
            }
        }
    }

    if (!hasLegion) {
        cout << "Lena\n";
        return 0;
    }

    bool possible = true;

    for (int lr = 1; lr <= N; ++lr) {
        for (int lc = 1; lc <= N; ++lc) {
            if (grid[lr][lc] == 1) {
                bool eliminable = false;

                int dr[] = {-1, +1, 0, 0};
                int dc[] = {0, 0, -1, +1};

                for (int d = 0; d < 4; ++d) {
                    int r = lr + dr[d];
                    int c = lc + dc[d];

                    if (r >= 1 && r <= N && c >= 1 && c <= N) {
                        if ((r + c) % 2 == parity_s) {
                            eliminable = true;
                            break;
                        }
                    }
                }

                if (!eliminable) {
                    cout << "Kiriya\n";
                    return 0;
                }
            }
        }
    }

    cout << "Lena\n";
    return 0;
}