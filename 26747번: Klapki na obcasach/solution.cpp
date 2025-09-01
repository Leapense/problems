#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    int M;
    cin >> M;
    vector<long long> A(M);
    for (int j = 0; j < M; ++j) cin >> A[j];
    
    long long T;
    cin >> T;

    long long base = 0;
    vector<long long> need;
    need.reserve(N);

    for (auto h : H) {
        if (h >= T) ++base;
        else need.push_back(T - h);
    }

    sort(need.begin(), need.end());
    sort(A.begin(), A.end());

    long long match = 0;
    size_t i = 0, j = 0;

    while (i < need.size() && j < A.size()) {
        if (A[j] >= need[i]) {
            ++match;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    cout << (base + match) << "\n";
    return 0;
}