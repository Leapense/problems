#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

typedef unsigned long long ull;

ull floor_sqrt(ull n) {
    if (n == 0) return 0;
    ull low = 1, high = 2;
    while (high * high <= n) {
        low = high;
        high *= 2;
    }
    ull ans = 0;
    while (low <= high) {
        ull mid = low + (high - low) / 2;
        if (mid <= n / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

ull gcd(ull a, ull b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main() {
    ull a, b;
    cin >> a >> b;

    ull num = floor_sqrt(b) - floor_sqrt(a);
    ull den = b - a;

    if (num == 0) {
        cout << 0 << endl;
    } else {
        ull common_divisor = gcd(num, den);
        cout << num / common_divisor << "/" << den / common_divisor << endl;
    }

    return 0;
}