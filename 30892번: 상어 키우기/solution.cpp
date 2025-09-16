#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    long long T;
    if (!(cin >> N >> K >> T)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    priority_queue<long long> pq;

    int i = 0;
    while (i < N && A[i] < T) pq.push(A[i++]);
    for (int step = 0; step < K; ++step) {
        if (pq.empty()) break;
        T += pq.top();
        pq.pop();

        while (i < N && A[i] < T) pq.push(A[i++]);
    }

    cout << T << '\n';
    return 0;
}