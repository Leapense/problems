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
    }
}