#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;

    cin >> N >> K;
    vector<int> sieve_limit;

    int limit = 65536;

    vector<bool> is_prime(limit+1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            sieve_limit.push_back(i);
            for (int j = 2 * i; j <= limit; j += i) is_prime[j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        unsigned int num;
        cin >> num;

        string s = to_string(num);
        bool cond1 = true;
        int cnt = 1;

        for (int j = 1; j < s.size(); j++) {
            if (s[j] == s[j - 1]) {
                cnt++;
                if (cnt > 3) {
                    cond1 = false;
                    break;
                }
            } else {
                cnt = 1;
            }
        }

        bool cond2 = true;

        if (num != 1) {
            unsigned int smallest = num;
            for (auto p : sieve_limit) {
                if ((long long) p * p > num) break;
                if (num % p == 0) {
                    smallest = p;
                    break;
                }
            }

            if (smallest != num) {
                if (smallest <= K) {
                    cond2 = false;
                }
            } else {
                if (num <= K) {
                    cond2 = false;
                }
            }
        }

        if (num == 1) {
            cond2 = true;
        }
        if (cond1 && cond2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}