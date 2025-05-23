#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long sum = 0;
    if (a <= 4 && 4 <= b) {
        sum += 4;
    }
    long long lower = max(a, 6LL);
    long long upper = b;
    if (lower <= upper) {
        long long n = upper - lower + 1;
        sum += (lower + upper) * n / 2;
    }
    cout << sum << endl;
    return 0;
}
