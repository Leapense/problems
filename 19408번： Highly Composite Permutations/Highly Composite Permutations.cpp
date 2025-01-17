#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
bool is_prime[MAX + 1];

void sieve() {
    fill(is_prime, is_prime + MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int n;
    cin >> n;

    if (n == 1 || n == 2) {
        cout << "-1\n";
        return 0;
    }

    vector<int> remaining;
    for (int i = 1; i <= n; i++) remaining.push_back(i);

    sort(remaining.begin(), remaining.end(), [&](const int &a, const int &b) -> bool {
        return a > b;
    });

    vector<int> permutation;
    long long sum = 0;

    bool found = false;

    for (int i = 0; i < remaining.size(); i++) {
        if (remaining[i] > 1 && !is_prime[remaining[i]]) {
            permutation.push_back(remaining[i]);
            sum += remaining[i];
            remaining.erase(remaining.begin() + i);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "-1\n";
        return 0;
    }

    while (!remaining.empty()) {
        bool selected = false;
        for (int i = 0; i < remaining.size(); i++) {
            int candidate = remaining[i];
            long long new_sum = sum + candidate;

            if (new_sum > 1 && !is_prime[new_sum]) {
                permutation.push_back(candidate);
                sum += candidate;
                remaining.erase(remaining.begin() + i);
                selected = true;
                break;
            }
        }

        if (!selected) {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < permutation.size(); i++) {
        if (i > 0) cout << " ";
        cout << permutation[i];
    }

    cout << "\n";

    return 0;
}