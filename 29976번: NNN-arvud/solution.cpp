#include <bits/stdc++.h>
using namespace std;

static string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void dfs(int d, int N, vector<int> &chosen, int cnt, int wgt, vector<string> &out)
{
    if (d == N)
    {
        long long c0 = 0;
        for (int i = 2; i < N; i++)
            c0 += (long long)(i - 1) * chosen[i];
        if (c0 < 0 || c0 > N)
            return;
        long long c1 = N - cnt - c0;
        if (c1 < 0 || c1 > N)
            return;
        if (wgt + c1 != N)
            return;
        vector<int> c(N);
        c[0] = c0;
        c[1] = c1;
        for (int i = 2; i < N; i++)
            c[i] = chosen[i];
        vector<int> seq(N);
        seq[0] = c[0];
        for (int i = 1; i < N; i++)
            seq[i] = c[N - i];
        for (int v : seq)
            if (v >= N)
                return;
        vector<int> check(N);
        for (int v : seq)
            check[v]++;
        if (check != c)
            return;
        string s;
        s.reserve(N);
        for (int v : seq)
            s.push_back(digits[v]);
        out.push_back(move(s));
        return;
    }
    int rem_cnt = N - cnt;
    int rem_wgt = N - wgt;
    if (rem_cnt < 0 || rem_wgt < 0)
        return;
    int lim = min(rem_cnt, rem_wgt / d);
    for (int v = 0; v <= lim; v++)
    {
        chosen[d] = v;
        dfs(d + 1, N, chosen, cnt + v, wgt + d * v, out);
    }
    chosen[d] = 0;
}

vector<string> solve(int N)
{
    vector<int> chosen(N);
    vector<string> ans;
    dfs(2, N, chosen, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N))
        return 0;
    auto res = solve(N);
    if (res.empty())
        cout << "EI OLE\n";
    else
        for (auto &s : res)
            cout << s << '\n';
    return 0;
}