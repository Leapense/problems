#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    if (!(cin >> N >> M)) return 0;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    int i = 0;
    int j = N - 1;
    long long teams = 0;
    while (i < j) {
        if (a[i] + a[j] >= M) {
            ++teams;
            ++i;
            --j;
        } else {
            ++i;
        }
    }
    cout << teams << "\n";
    return 0;
}