#include <bits/stdc++.h>
using namespace std;

int count_digits(long long num) {
    if (num == 0) return 1;
    int digits = 0;
    while (num > 0) {
        num /= 10;
        digits++;
    }

    return digits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;

    long long total_digits = 0;

    for (int d = 2; d <= 18; d++) {
        long long lower = pow(10, d - 1);
        long long upper = pow(10, d) - 1;

        if (lower < 10) lower = 10;
        if (lower > n) break;

        upper = min(upper, n);

        long long first = lower;
        if (first % 10 != 0) {
            first += (10 - first % 10);
        }

        if (first > upper) continue;
        long long last = upper - (upper % 10);
        long long count = (last - first) / 10 + 1;
        total_digits += count * d;
    }

    total_digits += count_digits(1);

    if (n != 1 && n % 10 != 0) {
        total_digits += count_digits(n);
    }


    cout << total_digits << endl;

    return 0;
}