#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long k;
    cin >> k;

    long long minEdge = LLONG_MAX;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        minEdge = min(minEdge, w);
    }

    cout << (k - 1) * minEdge << "\n";

    return 0;
}