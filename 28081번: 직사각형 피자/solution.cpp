#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long W, H, K;
    if (!(cin >> W >> H >> K)) return 0;

    int N;
    cin >> N;
    vector<long long> y(N);
    for (int i = 0; i < N; ++i) cin >> y[i];

    int M;
    cin >> M;
    vector<long long> x(M);
    for (int i = 0; i < M; ++i) cin >> x[i];

    vector<long long> xs; xs.reserve(M + 2);
    xs.push_back(0);
    xs.insert(xs.end(), x.begin(), x.end());
    xs.push_back(W);

    vector<long long> ys; ys.reserve(N + 2);
    ys.push_back(0);
    ys.insert(ys.end(), y.begin(), y.end());
    ys.push_back(H);

    vector<long long> Wseg, Hseg;
    Wseg.reserve(M + 1);
    Hseg.reserve(N + 1);

    for (int i = 0; i + 1 < (int)xs.size(); ++i) Wseg.push_back(xs[i + 1] - xs[i]);
    for (int i = 0; i + 1 < (int)ys.size(); ++i) Hseg.push_back(ys[i + 1] - ys[i]);

    sort(Wseg.begin(), Wseg.end());
    sort(Hseg.begin(), Hseg.end());

    unsigned long long ans = 0;
    int j = (int)Hseg.size() - 1;
    for (long long w : Wseg) {
        while (j >= 0) {
            __int128 prod = (__int128)w * (__int128)Hseg[j];
            if (prod <= (__int128)K) break;
            --j;
        }
        if (j < 0) break;
        ans += (unsigned long long)(j + 1);
    }

    cout << ans << '\n';
    return 0;
}