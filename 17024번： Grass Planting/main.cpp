#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> degree(N + 1, 0);

    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int maxDegree = 0;
    for (int i = 1; i <= N; i++)
    {
        maxDegree = max(maxDegree, degree[i]);
    }

    cout << maxDegree + 1 << endl;

    return 0;
}