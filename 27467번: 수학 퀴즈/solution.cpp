#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    long long cnt[3] = {0, 0, 0};
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        cnt[a % 3]++;
    }

    long long p = cnt[1] - cnt[2];
    long long q = cnt[0] - cnt[2];
    cout.setf(ios::fixed);
    cout << setprecision(9) << (double)p << ' ' << (double)q << '\n';
    return 0;
}