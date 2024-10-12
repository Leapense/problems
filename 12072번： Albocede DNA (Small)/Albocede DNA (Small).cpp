#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int addMod(int x, int y) {return (x + y) % MOD;}
int subMod(int x, int y) {return (x - y + MOD) % MOD;}

int solve(string S) {
    int n = S.length();

    vector<vector<vector<int>>> wayNums(n + 1, vector<vector<int>>(n + 1, vector<int>(4, 0)));
    wayNums[0][0][3] = 1;

    for (char ch : S) {
        vector<vector<vector<int>>> nextWayNums(n + 1, vector<vector<int>>(n + 1, vector<int>(4, 0)));

        for (int acDiff = 0; acDiff <= n; ++acDiff) {
            for (int bdDiff = 0; bdDiff <= n; ++bdDiff) {
                nextWayNums[acDiff][bdDiff] = wayNums[acDiff][bdDiff];
            }
        }

        for (int acDiff = 0; acDiff <= n; ++acDiff) {
            for (int bdDiff = 0; bdDiff <= n; ++bdDiff) {
                if (ch == 'a') {
                    if (acDiff == 0 && bdDiff == 0) {
                        nextWayNums[1][0][0] = addMod(nextWayNums[1][0][0], wayNums[0][0][3]);
                    }
                    if (acDiff != n && bdDiff == 0) {
                        nextWayNums[acDiff + 1][0][0] = addMod(nextWayNums[acDiff + 1][0][0], wayNums[acDiff][0][0]);
                    }
                } else if (ch == 'b') {
                    if (bdDiff == 1) {
                        nextWayNums[acDiff][1][1] = addMod(nextWayNums[acDiff][1][1], wayNums[acDiff][0][0]);
                    }
                    if (bdDiff != n) {
                        nextWayNums[acDiff][bdDiff + 1][1] = addMod(nextWayNums[acDiff][bdDiff + 1][1], wayNums[acDiff][bdDiff][1]);
                    }
                } else if (ch == 'c') {
                    if (acDiff != 0) {
                        nextWayNums[acDiff - 1][bdDiff][2] = addMod(nextWayNums[acDiff - 1][bdDiff][2], wayNums[acDiff][bdDiff][1]);
                        nextWayNums[acDiff - 1][bdDiff][2] = addMod(nextWayNums[acDiff - 1][bdDiff][2], wayNums[acDiff][bdDiff][2]);
                    }
                } else {
                    if (acDiff == 0 && bdDiff != 0) {
                        nextWayNums[0][bdDiff - 1][3] = addMod(nextWayNums[0][bdDiff - 1][3], wayNums[0][bdDiff][2]);
                        nextWayNums[0][bdDiff - 1][3] = addMod(nextWayNums[0][bdDiff - 1][3], wayNums[0][bdDiff][3]);
                    }
                }
            }
        }

        wayNums = nextWayNums;
    }

    return subMod(wayNums[0][0][3], 1);
}

int main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        string S;
        cin >> S;

        cout << "Case #" << tc << ": " << solve(S) << "\n";
    }

    return 0;
}