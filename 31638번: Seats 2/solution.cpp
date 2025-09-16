#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long x, c;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<Node> v(N);
    for (int i = 0; i < N; ++i) {
        long long C, X;
        cin >> C >> X;
        v[i] = {X, C, i};
    }
    sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
        if (a.x != b.x) return a.x < b.x;
        if (a.c != b.c) return a.c < b.c;
        return a.idx < b.idx;
    });

    const long long INF = (1LL << 62);
    int n = N;
    vector<int> leftDiff(n, -1), rightDiff(n, -1);

    for (int i = 0; i < n; ++i) {
        if (i == 0) { leftDiff[i] = -1; continue; }
        if (v[i-1].c != v[i].c) leftDiff[i] = i-1;
        else leftDiff[i] = leftDiff[i-1];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) { rightDiff[i] = -1; continue; }
        if (v[i+1].c != v[i].c) rightDiff[i] = i+1;
        else rightDiff[i] = rightDiff[i+1];
    }

    vector<long long> ans(N, 0);
    for (int i = 0; i < n; ++i) {
        long long dl = (leftDiff[i] == -1) ? INF : (v[i].x - v[leftDiff[i]].x);
        long long dr = (rightDiff[i] == -1) ? INF : (v[rightDiff[i]].x - v[i].x);
        ans[v[i].idx] = min(dl, dr);
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}