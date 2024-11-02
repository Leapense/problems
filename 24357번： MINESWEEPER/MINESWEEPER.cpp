#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int grid[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == 9) {
                cout << 9;
            } else {
                int bombCount = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;

                        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3 && grid[ni][nj] == 9) {
                            bombCount++;
                        }
                    }
                }
                cout << bombCount;
            }

            if (j != 2) cout << " ";
        }

        cout << endl;
    }

    return 0;
}