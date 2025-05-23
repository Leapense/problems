#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;

    while (cin >> N >> S) {
        int L = S.length();

        int totalB = 0, totalF = 0, totalS = 0;

        for (char c : S) {
            if (c == 'B') totalB++;
            else if (c == 'F') totalF++;
            else if (c == 'S') totalS++;
        }

        if (totalB != totalF or totalB != totalS) {
            cout << "Impossible\n";
            continue;
        }

        int totalK = totalB;
        if (totalK < N) {
            cout << "Impossible\n";
            continue;
        }

        vector<int> prefixB(L+1, 0);
        vector<int> prefixF(L+1, 0);
        vector<int> prefixS(L+1, 0);

        for (int i = 1; i <= L; i++) {
            prefixB[i] = prefixB[i-1] + (S[i-1] == 'B');
            prefixF[i] = prefixF[i-1] + (S[i-1] == 'F');
            prefixS[i] = prefixS[i-1] + (S[i-1] == 'S');
        }

        vector<vector<int>> dp (N+1, vector<int>(L+1, 0));

        dp[0][0] = 1;

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= L; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[k-1][j] > 0) {
                        int cntB = prefixB[i] - prefixB[j];
                        int cntF = prefixF[i] - prefixF[j];
                        int cntS = prefixS[i] - prefixS[j];

                        if (cntB == cntF and cntB == cntS and cntB >= 1) {
                            dp[k][i] += dp[k-1][j];
                        }
                    }
                }
            }
        }

        if (dp[N][L] == 0) {
            cout << "Impossible\n";
        } else {
            cout << dp[N][L] << "\n";
        }
    }

    return 0;
}