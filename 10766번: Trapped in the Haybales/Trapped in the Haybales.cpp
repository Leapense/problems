#include <bits/stdc++.h>
using namespace std;

static const long long INF = 1000000000000LL; // 10^12

struct Bale {
    long long s, p;
};

int N;
Bale bales[4002];
bool visited[4002][4002];
bool dp[4002][4002]; // dp[i][j] = canEscape(i,j)

bool canEscapeMemo(int i, int j) {
    // If one end is open, we can escape
    if (i == 0 || j == N+1) return true;
    if (visited[i][j]) return dp[i][j];
    visited[i][j] = true;
    long long dist = bales[j].p - bales[i].p;

    bool res = false;
    // Try breaking left bale i
    if (dist > bales[i].s && i > 0) {
        res = res || canEscapeMemo(i-1, j);
    }
    // Try breaking right bale j
    if (!res && dist > bales[j].s && j < N+1) {
        res = res || canEscapeMemo(i, j+1);
    }

    dp[i][j] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> bales[i].s >> bales[i].p;
    }
    // Add dummy bales
    bales[0].s = 0; bales[0].p = -INF;
    bales[N+1].s = 0; bales[N+1].p = INF;

    sort(bales, bales+N+2, [](const Bale &a, const Bale &b){
        return a.p < b.p;
    });

    // We have a total of N+2 bales (including dummy)
    // Check intervals between consecutive bales from 0..N
    long long result = 0;
    for (int i=0; i<=N; i++) {
        // Interval between bale i and bale i+1
        // If can't escape from this interval, add length
        if (!canEscapeMemo(i, i+1)) {
            result += bales[i+1].p - bales[i].p;
        }
    }

    cout << result << "\n";

    return 0;
}