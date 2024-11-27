#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAX = 46340;
    vector<bool> is_prime(MAX + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX; i++) if (is_prime[i]) {
        for (int j = i * i; j <= MAX; j += i) is_prime[j] = false;
    }

    vector<int> primes;

    for (int i = 2; i <= MAX; i++) if (is_prime[i]) primes.push_back(i);

    int n;
    cin >> n;

    while(n--) {
        long long num;
        cin >> num;

        long long tmp = num;

        vector<long long> factors;

        for (auto p : primes) {
            if (p * p > tmp) break;
            while (tmp % p == 0) {
                factors.push_back(p);
                tmp /= p;
            }
        }
        if (tmp > 1) factors.push_back(tmp);
        cout << num << ": ";
        if (factors.empty()) {
            cout << "prime\n";
        } else {
            bool isPrime = (factors.size() == 1 && factors[0] == num);
            if (isPrime) {
                cout << "prime\n";
            } else {
                for (int i = 0; i < factors.size(); i++) {
                    if (i > 0) cout << " ";
                    cout << factors[i];
                }

                cout << "\n";
            }
        }
    }

    return 0;
}