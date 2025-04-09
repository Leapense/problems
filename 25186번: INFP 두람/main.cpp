#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> v(N);
    long long sum = 0, mx = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
    }

    // Corner case: only 1 total outfit
    if (sum == 1)
    {
        cout << "Happy\n";
        return 0;
    }

    // General circle condition
    if (2LL * mx <= sum)
    {
        cout << "Happy\n";
    }
    else
    {
        cout << "Unhappy\n";
    }

    return 0;
}
