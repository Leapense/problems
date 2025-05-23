#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        int N, M;
        cin >> N >> M;
        vector<double> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        cout << "Case #" << test << ":" << endl;
        for (int q = 0; q < M; q++) {
            int L, R;
            cin >> L >> R;
            int D = R - L + 1;
            double sum_log = 0.0;
            for (int i = L; i <= R; i++) {
                sum_log += log(a[i]);
            }
            double s = exp(sum_log / D);
            cout << fixed << setprecision(9) << s << endl;
        }
    }

    return 0;
}