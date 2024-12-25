#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateExpectedKeystrokes(int A, int B, const vector<double>& p) {
    double minExpected = B + 2;

    double probAllCorrect = 1.0;
    for (int i = 0; i < A; ++i) {
        probAllCorrect *= p[i];
    }

    double expected1 = probAllCorrect * (B - A + 1) + (1 - probAllCorrect) * (B - A + 1 + B + 1);
    minExpected = min(minExpected, expected1);

    for (int backspaces = 1; backspaces <= A; ++backspaces) {
        double probCorrect = 1.0;
        for (int i = 0; i < A - backspaces; ++i) {
            probCorrect *= p[i];
        }

        double expected2 = probCorrect * (backspaces + B - (A - backspaces) + 1) + (1 - probCorrect) * (backspaces + B - (A - backspaces) + 1 + B + 1);
        minExpected = min(minExpected, expected2);
    }

    return minExpected;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int A, B;
        cin >> A >> B;
        vector<double> p(A);

        for (int i = 0; i < A; ++i) {
            cin >> p[i];
        }

        double result = calculateExpectedKeystrokes(A, B, p);
        cout << "Case #" << t << ": " << fixed << setprecision(6) << result << endl;
    }

    return 0;
}