#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    bool found = false;

    long long m, k;

    for (long long b = 1; b * b <= n; b++) {
        if (n % b == 0) {
            long long a = n / b;
            if (a > b && (a + b) % 2 == 0 && (a - b) % 2 == 0) {
                m = (a + b) / 2;
                k = (a - b) / 2;

                cout << m << " " << k;
                return 0;
            }
        }
    }

    if (n == 1) {
        cout << 1 << " " << 0;
        return 0;
    }

    cout << "impossible\n";

    return 0;
}