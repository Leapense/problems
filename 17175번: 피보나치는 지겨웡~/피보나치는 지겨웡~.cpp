#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;

int fibonacci_calls(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    int prev2 = 1, prev1 = 1;

    for (int i = 2; i <= n; ++i) {
        int current = (prev1 + prev2 + 1) % MOD;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci_calls(n) << endl;
    return 0;
}