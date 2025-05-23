#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, X, K, A, B, C;
        cin >> N >> X >> K >> A >> B >> C;
        double expected = 0.0;
        for (int i = 0; i < 15; i++) {
            int k_i = (K >> i) & 1;
            int x_i = (X >> i) & 1;
            double a, b, aN, pN;
            if (k_i == 0) {
                a = (B + C) / 100.0;
                b = 0.0;
            } else {
                a = (A - C) / 100.0;
                b = (B + C) / 100.0;
            }
            if (abs(a - 1.0) > 1e-12) {
                aN = pow(a, N);
                pN = aN * x_i + b * (1 - aN) / (1 - a);
            } else {
                pN = x_i + b * N;
            }
            expected += pN * (1 << i);
        }
        cout << "Case #" << t << ": " << fixed << setprecision(10) << expected << endl;
    }

    return 0;
}