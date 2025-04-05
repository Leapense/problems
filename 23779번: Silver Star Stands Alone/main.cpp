#include <bits/stdc++.h>
using namespace std;

vector<int> sievePrimes(int maxVal) {
    vector<bool> isPrime(maxVal + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= maxVal; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxVal; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= maxVal; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    cin >> P;

    vector<int> primes = sievePrimes(P);

    int n = (int)primes.size();
    vector<long long> dp(n, 0LL);

    int startIndex = -1;
    for (int i = 0; i < n; i++) {
        if (primes[i] == 2) {
            startIndex = i;
            break;
        }
    }
    dp[startIndex] = 1LL;

    for (int i = startIndex + 1; i < n; i++) {
        for (int j = startIndex; j < i; j++) {
            if (primes[i] - primes[j] <= 14) {
                dp[i] += dp[j];
            }
        }
    }

    int endIndex = -1;
    for (int i = 0; i < n; i++) {
        if (primes[i] == P) {
            endIndex = i;
            break;
        }
    }

    cout << dp[endIndex] << "\n";
    return 0;
}
