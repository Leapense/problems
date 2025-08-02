#include <bits/stdc++.h>
using namespace std;

static constexpr int MAX_P = 250000;

static vector<int> buildPrimes() {
    vector<bool> sieve(MAX_P + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i * 1LL * i <= MAX_P; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAX_P; j += i) {
                sieve[j] = false;
            }
        }
    }

    vector<int> primes;
    primes.reserve(30000);

    for (int i = 2; i <= MAX_P; ++i) {
        if(sieve[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int> primes = buildPrimes();
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> x(n);
        for (int &v : x) {
            cin >> v;
        }

        sort(x.begin(), x.end());

        long long best = numeric_limits<long long>::max();
        for (size_t s = 0; s + n <= primes.size(); ++s) {
            long long cost = 0;
            for (int i = 0; i < n; ++i) {
                cost += llabs(x[i] - primes[s + i]);
                if (cost >= best) {
                    break;
                }
            }

            best = min(best, cost);
        }

        cout << best << "\n";
    }

    return 0;
}