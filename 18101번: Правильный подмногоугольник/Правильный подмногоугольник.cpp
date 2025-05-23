#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    vector<long long> divisors;

    if (N == 3) {
        cout << 3 << "\n";
        return 0;
    }

    long long limit = (long long)floor(sqrt((long double) N));

    for (long long i = 1; i <= limit; i++) {
        if (N % i == 0) {
            if (i >= 3) {
                divisors.push_back(i);
            }

            long long paired = N / i;
            if (paired >= 3 && paired != i) {
                divisors.push_back(paired);
            }
        }
    }

    if (divisors.empty()) {
        cout << N << "\n";
        return 0;
    }

    sort(divisors.begin(), divisors.end());
    cout << divisors.front() << "\n";

    return 0;
}