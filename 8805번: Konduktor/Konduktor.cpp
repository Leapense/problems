#include <iostream>
#include <vector>

using namespace std;

int main() {
    int Z;
    cin >> Z;

    while (Z--) {
        long long N, K;
        cin >> N >> K;

        vector<long long> counts(N, 0);

        if (N == 1) {
            counts[0] = K;
        } else {
            long long fullCycleLength = 2 * N - 2;
            long long fullCycles = K / fullCycleLength;
            long long remainder = K % fullCycleLength;

            for (int i = 0; i < N; ++i) {
                if (i == 0 || i == N - 1) {
                    counts[i] = fullCycles;
                } else {
                    counts[i] = 2 * fullCycles;
                }
            }

            int pos = 0;

            for (int i = 0; i < remainder; ++i) {
                counts[pos]++;

                if (pos == N - 1) {
                    for (int j = N - 2; j >= 0 && i < remainder - 1; --j) {
                        i++;
                        counts[j]++;
                    }

                    break;
                }

                pos++;
            }
        }

        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << counts[i];
        }

        cout << endl;
    }

    return 0;
}