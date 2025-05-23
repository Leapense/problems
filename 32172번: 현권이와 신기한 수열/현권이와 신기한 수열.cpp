#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    cin >> N;

    vector<long long> A(N + 1, 0);

    unordered_set<long long> s;
    s.reserve(200000);
    s.insert(0);

    for (long long i = 1; i <= N; i++) {
        long long candidate1 = A[i - 1] - i;
        if (candidate1 >= 0 && s.find(candidate1) == s.end()) {
            A[i] = candidate1;
        } else {
            A[i] = A[i - 1] + i;
        }
        s.insert(A[i]);
    }

    cout << A[N] << "\n";

    return 0;
}