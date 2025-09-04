#include <bits/stdc++.h>
using namespace std;

string s;
int len;
int digits[32];
long long memo[20][14][2][2][2];

long long dfs(int pos, int sum, int prev1, int has13, int started, int tight) {
    if (pos == len) return (started && sum == 13 && has13) ? 1 : 0;
    if (!tight && memo[pos][sum][prev1][has13][started] != -1) return memo[pos][sum][prev1][has13][started];
    int up = tight ? digits[pos] : 9;
    long long res = 0;
    for (int d = 0; d <= up; ++d) {
        int nstarted = started || d != 0;
        int nsum = sum + (nstarted ? d : 0);
        if (nsum > 13) continue;
        int nhas13 = has13 || (prev1 && nstarted && d == 3);
        int nprev1 = nstarted ? (d == 1) : 0;
        int ntight = tight && (d == up);
        res += dfs(pos + 1, nsum, nprev1, nhas13, nstarted, ntight);
    }
    if (!tight) memo[pos][sum][prev1][has13][started] = res;
    return res;
}

int main()
{
    if (!(cin >> s)) return 0;
    len = s.size();
    for (int i = 0; i < len; ++i) digits[i] = s[i] - '0';
    memset(memo, -1, sizeof(memo));
    cout << dfs(0,0,0,0,0,1) << "\n";
    return 0;
}