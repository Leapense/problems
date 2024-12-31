#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long S;
    cin >> S;

    int M = (1 << N) - 1;

    vector<long long> scores(M);

    for (auto &x : scores) cin >> x;
    if (N == 0) {
        cout << "YES";
        return 0;
    }

    sort(scores.begin(), scores.end(), greater<long long>());
    long long sum = 0;

    for (int i = 0; i < N; i++) sum += scores[i];
    if (S <= sum) cout << "YES";
    else cout << "NO";

    return 0;
}