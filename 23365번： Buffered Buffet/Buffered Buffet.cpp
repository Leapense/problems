#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> d(n);
    for (auto &x : d)
        cin >> x;

    sort(d.begin(), d.end());
    long long sum = 0;

    for (auto x : d)
        sum += x;
    long long C = sum + d[n - 1] - d[0];

    cout << C << endl;
    return 0;
}