#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

double calculateExpectedKeystrokes(int A, int B, const vector<double>& p) {
    // 누적 곱 계산: probCorrect[i] = p[0] * p[1] * ... * p[i-1]
    vector<double> probCorrect(A + 1, 1.0);
    for (int i = 1; i <= A; ++i) {
        probCorrect[i] = probCorrect[i - 1] * p[i - 1];
    }

    double minExpected = B + 2; // 전략 3의 기댓값 (바로 엔터 누르기)

    // 전략 1: 계속 입력하기
    double expected1 = probCorrect[A] * (B - A + 1) + (1 - probCorrect[A]) * (B - A + 1 + B + 1);
    minExpected = min(minExpected, expected1);

    // 전략 2: 백스페이스 누르기
    for (int backspaces = 1; backspaces <= A; ++backspaces) {
        double prob = probCorrect[A - backspaces];
        double expected2 = prob * (backspaces + B - (A - backspaces) + 1) + (1 - prob) * (backspaces + B - (A - backspaces) + 1 + B + 1);
        minExpected = min(minExpected, expected2);
    }

    return minExpected;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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