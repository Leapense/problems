#include <bits/stdc++.h>
using namespace std;

static int max_domino_chain_length(const vector<long long>& a) {
    const int n = static_cast<int>(a.size());
    if (n <= 0) return 0;
    vector<long long> best(n + 2, -1);
    vector<long long> nextForI(n + 2, -1);
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        fill(nextForI.begin(), nextForI.end(), -1);
        for (int len = 1; len <= i; ++len) {
            if (best[len] >= a[i]) {
                long long candidateSum = best[len] + a[i];
                if (candidateSum > nextForI[len + 1]) nextForI[len + 1] = candidateSum;
                if (len + 1 > maxLength) maxLength = len + 1;
            }
        }
        if (a[i] > nextForI[1]) {
            nextForI[1] = a[i];
            if (maxLength < 1) maxLength = 1;
        }
        for (int len = 1; len <= n; ++len) {
            if (nextForI[len] > best[len]) best[len] = nextForI[len];
        }
    }
    return maxLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << max_domino_chain_length(a) << "\n";
    return 0;
}