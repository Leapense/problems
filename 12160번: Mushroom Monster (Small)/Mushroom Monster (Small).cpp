#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        int N;
        cin >> N;
        vector<int> m(N);
        for (int i = 0; i < N; i++) {
            cin >> m[i];
        }
        int z1 = 0;
        for (int i = 0; i < N - 1; i++) {
            if (m[i] > m[i + 1]) {
                z1 += m[i] - m[i + 1];
            }
        }

        double r = 0.0;
        for (int i = 0; i < N - 1; i++) {
            if (m[i] > m[i + 1]) {
                double rate = (m[i] - m[i + 1]) / 10.0;
                if (rate > r) {
                    r = rate;
                }
            }
        }

        double z2 = 0.0;

        for (int i = 0; i < N - 1; i++) {
            if (m[i] >= r * 10.0) {
                z2 += r * 10.0;
            } else {
                z2 += m[i];
            }
        }
        int z2_int = static_cast<int>(z2 + 1e-9);

        cout << "Case #" << test << ": " << z1 << " " << z2_int << endl;
    }

    return 0;
}