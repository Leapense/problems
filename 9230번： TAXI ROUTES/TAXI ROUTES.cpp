#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int streets, avenues;
    int mapCount = 0;

    while (true) {
        cin >> streets >> avenues;
        if (!cin || (streets == 0 && avenues == 0)) break;

        mapCount++;

        vector<vector<bool>> blocked(streets, vector<bool>(avenues, false));
        while (true) {
            int s, a;
            cin >> s >> a;
            if (!cin || (s == 0 && a == 0)) break;
            blocked[s][a] = true;
        }

        vector<vector<int>> dp(streets, vector<int>(avenues, 0));
        dp[0][0] = 1;

        for (int s = 0; s < streets; s++) {
            for (int a = 0; a < avenues; a++) {
                if (s == 0 && a == 0) continue;
                if (blocked[s][a]) {
                    dp[s][a] = 0;
                } else {
                    int up = (s > 0) ? dp[s-1][a] : 0;
                    int left = (a > 0) ? dp[s][a-1] : 0;
                    dp[s][a] = up + left;
                }
            }
        }

        cout << "Map " << mapCount << ": " << dp[streets-1][avenues-1] << "\n";
    }

    return 0;
}