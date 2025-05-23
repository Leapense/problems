#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll count_no_nine(const string& num) {
    int n = num.size();
    long long dp[20][2][2];
    memset(dp, -1, sizeof(dp));

    function<long long(int, int, int)> dfs = [&](int pos, int tight, int leading_zero) -> long long {
        if (pos == n) return leading_zero ? 0 : 1;
        if (dp[pos][tight][leading_zero] != -1) return dp[pos][tight][leading_zero];
        int limit = tight ? (num[pos] - '0') : 8;
        long long res = 0;
        for (int d = 0; d <= limit; d++) {
            if (d == 9) continue;
            int new_tight = tight && (d == (num[pos] - '0'));
            int new_leading_zero = leading_zero && (d == 0);
            res += dfs(pos + 1, new_tight, new_leading_zero);
        }
        return dp[pos][tight][leading_zero] = res;
    };
    return dfs(0, 1, 1);
}

string decrement(const string &num) {
    string res = num;
    int i = res.size() - 1;
    while (i >= 0 && res[i] == '0') {
        res[i] = '9';
        i--;
    }

    if (i >= 0) res[i]--;

    int start = 0;
    while (start < res.size() - 1 && res[start] == '0') start++;
    return res.substr(start);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string l_str, r_str;
    cin >> l_str >> r_str;

    auto contains_nine = [&](const string& s) -> bool {
        return s.find('9') != string::npos;
    };

    string l_minus = decrement(l_str);
    ll count_r = count_no_nine(r_str);
    ll count_l_minus = (l_minus.empty()) ? 0 : count_no_nine(l_minus);
    cout << count_r - count_l_minus;

    return 0;
}