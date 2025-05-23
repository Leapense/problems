#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        double F;
        cin >> N >> F;
        string s;
        cin >> s;

        vector<int> binary_sequence(N);
        for (int i = 0; i < N; i++) {
            binary_sequence[i] = s[i] - '0';
        }

        vector<int> prefix(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            prefix[i] = prefix[i - 1] + binary_sequence[i - 1];
        }

        double smallest_diff = numeric_limits<double>::infinity();
        int best_index = 0;

        for (int L = 1; L <= N; L++) {
            for (int i = 0; i <= N - L; i++) {
                int actual_1s = prefix[i + L] - prefix[i];
                double fraction = (double)actual_1s / L;
                double difference = fabs(fraction - F);

                if (difference < smallest_diff) {
                    smallest_diff = difference;
                    best_index = i;
                } else if (difference == smallest_diff && i < best_index) {
                    best_index = i;
                }
            }
        }

        cout << "Case #" << t << ": " << best_index << endl;
    }

    return 0;
}