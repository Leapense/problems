#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long powMod(long long A, long long X) {
    long long result = 1;
    A = A % MOD;

    while (X > 0) {
        if (X % 2 == 1) {
            result = (result * A) % MOD;
        }
        A = (A * A) % MOD;
        X = X / 2;
    }
    return result;
}

int main() {
    long long A, X;
    cin >> A >> X;

    cout << powMod(A, X) << "\n";

    return 0;
}