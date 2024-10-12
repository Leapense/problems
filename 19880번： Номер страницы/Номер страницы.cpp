#include <bits/stdc++.h>
using namespace std;

vector<int> computeZ(const string& s) {
    int n = s.size();
    vector<int> Z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - 1]);
        }

        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    return Z;
}

int main()
{
    string S;
    cin >> S;

    int N = S.size();

    vector<int> Z = computeZ(S);
    long long count = 0;

    for(int k = 1; k < N; k++) {
        if (S[0] == '0') continue;
        if (S[k] == '0') continue;
        if (k < N - k) {
            count++;
        }
        else if(k == N - k) {
            int lcp = Z[k];
            if (lcp >= k) {
                count++;
            } else {
                if (S[lcp] < S[k + lcp]) {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}