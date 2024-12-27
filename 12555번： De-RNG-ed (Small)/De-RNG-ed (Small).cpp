#include <bits/stdc++.h>
using namespace std;

vector<int> sievePrimes(int maxN) {
    vector<bool> isPrime(maxN+1, true);
    isPrime[0] = false; 
    isPrime[1] = false;
    for (int i = 2; i * i <= maxN; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= maxN; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

long long modInverse(long long a, long long p) {
    long long result = 1;
    long long base = a % p;
    long long exp = p - 2;

    while (exp > 0) {
        if (exp & 1) result = (result * base) % p;
        base = (base * base) % p;
        exp >>= 1;
    }

    return result;
}

vector<pair<long long, long long>> findAllAb(const vector<long long> &seq, long long p) {
    int K = seq.size();

    if (K < 2) {
        return {};
    }

    long long x1 = -1, y1 = -1, x2 = -1, y2 = -1; 
    bool foundTwoPairs = false;

    for (int i = 0; i + 1 < K; i++) {
        if (x1 == -1) {
            x1 = seq[i];
            y1 = seq[i + 1];
        } else if (x2 == -1 && seq[i] != x1) {
            x2 = seq[i];
            y2 = seq[i + 1];
            foundTwoPairs = true;
            break;
        } 
    }

    vector<pair<long long, long long>> validPairs;

    bool allSame = true;
    for (int i = 1; i < K; i++) {
        if (seq[i] != seq[0]) {
            allSame = false;
            break;
        }
    }

    if (allSame) {
        long long c = seq[0];

        for (int A = 0; A < (int)p && A < 2; A++) {
            long long B = ((c - (A * c) % p) % p + p) % p;
            validPairs.push_back({A, B});
        }
        return validPairs;
    }

    if (!foundTwoPairs) {
        x2 = -1;
        for (int i = 0; i + 1 < K; i++) {
            if (seq[i] != x1) {
                x2 = seq[i];
                y2 = seq[i + 1];
                break;
            }
        }

        if (x2 == -1) {
            return {};
        }
    }

    auto invX1X2 = modInverse((x1 - x2 + p) % p, p);

    long long A = (((y1 - y2) % p + p) % p) * invX1X2 % p;
    long long B = ((y1 - (A * x1) % p) % p + p) % p;

    bool consistent = true;
    for (int i = 0; i+1 < K && consistent; i++) {
        long long lhs = (A * seq[i] + B) % p;
        if (lhs != seq[i+1]) {
            consistent = false;
        }
    }
    if (consistent) {
        validPairs.push_back({A, B});
    }

    return validPairs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> primes = sievePrimes(10000);

    int T;
    cin >> T;


    for (int t = 1; t <= T; t++) {
        int D, K;
        cin >> D >> K;
        vector<long long> seq(K);
        for (int i = 0; i < K; i++) {
            cin >> seq[i];
        }

        if (K == 1) {
            cout << "Case #" << t << ": I don't know." << "\n";
            continue;
        }

        unordered_set<long long> possibleNexts;

        long long maxP = 1;
        for (int i = 0; i < D; i++) {
            maxP *= 10;
        }

        for (int primeCandidate : primes) {
            if (primeCandidate > maxP) break;

            bool validRange = true;
            for (long long x : seq) {
                if (x >= primeCandidate) {
                    validRange = false;
                    break;
                }
            }

            if (!validRange) continue;

            auto abPairs = findAllAb(seq, primeCandidate);

            if (abPairs.empty()) {
                continue;
            }

            for (auto &pr : abPairs) {
                long long A = pr.first, B = pr.second;
                long long nxt = (A * seq[K - 1] + B) % primeCandidate;
                possibleNexts.insert(nxt);
            }
        }

        if (possibleNexts.size() == 0) {
            cout << "Case #" << t << ": I don't know." << "\n";
        } else if (possibleNexts.size() == 1) {
            cout << "Case #" << t << ": " << *possibleNexts.begin() << "\n";
        } else {
            cout << "Case #" << t << ": I don't know." << "\n";
        }
    }

    return 0;
}