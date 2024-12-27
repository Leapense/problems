#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int mod(int a, int m) {
    a %= m;
    if (a < 0) a += m;
    return a;
}

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) {
        return -1; // Inverse doesn't exist
    } else {
        return mod(x, m);
    }
}

void solve() {
    vector<int> primes = sieve(10000);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int D, K;
        cin >> D >> K;
        vector<int> S(K);
        for (int i = 0; i < K; i++) {
            cin >> S[i];
        }
        if (K == 1) {
            cout << "Case #" << t << ": I don't know." << endl;
            continue;
        }
        int M = *max_element(S.begin(), S.end());
        int P_max = pow(10, D);
        set<int> possible_next;
        for (int p : primes) {
            if (p > M && p <= P_max) {
                int diff1 = S[1] - S[0];
                int diff2 = S[2] - S[1];
                if (diff1 == 0) {
                    bool valid = true;
                    for (int i = 2; i < K; i++) {
                        if (S[i] != S[i-1]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        int B = mod(S[0], p);
                        possible_next.insert(mod(B, p));
                    }
                } else {
                    int inv = mod_inverse(diff1, p);
                    if (inv != -1) {
                        int A = mod(diff2 * inv, p);
                        int B = mod(S[1] - A * S[0], p);
                        bool valid = true;
                        for (int i = 2; i < K; i++) {
                            int expected = mod(A * S[i-1] + B, p);
                            if (expected != S[i]) {
                                valid = false;
                                break;
                            }
                        }
                        if (valid) {
                            int next_num = mod(A * S[K-1] + B, p);
                            possible_next.insert(next_num);
                        }
                    }
                }
            }
        }
        if (possible_next.size() == 1) {
            cout << "Case #" << t << ": " << *possible_next.begin() << endl;
        } else {
            cout << "Case #" << t << ": I don't know." << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}