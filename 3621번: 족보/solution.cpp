#include <bits/stdc++.h>
using namespace std;

long long needed_extra_people(int n, int d, const vector<int>& child)
{
    vector<int> indeg(n + 1, 0);
    for (int i = 1; i <= n; ++i) ++indeg[child[i]];

    long long answer = 0;
    for (int v = 0; v <= n; ++v)
    {
        int k = indeg[v];
        if (k > d) answer += 1LL * (k - 2) / (d - 1);
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    if (!(cin >> n >> d)) return 0;

    vector<int> child(n + 1);
    for (int i = 1; i <= n; ++i) cin >> child[i];

    cout << needed_extra_people(n, d, child) << "\n";
    return 0;
}