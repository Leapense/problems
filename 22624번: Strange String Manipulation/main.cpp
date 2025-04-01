#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> I(N);
    for (int i = 0; i < N; i++) {
        cin >> I[i];
    }

    double bestEntropy = numeric_limits<double>::max();
    int bestS = 0, bestA = 0, bestC = 0;

    for (int S = 0; S < 16; S++) {
        for (int A = 0; A < 16; A++) {
            for (int C = 0; C < 16; C++) {
                vector<int> O(N);
                int R_prev = S;

                for (int i = 0; i < N; i++) {
                    int R;
                    if (i == 0) {
                        R = (A * R_prev + C) % 256;
                    } else {
                        R = (A * R_prev + C) % 256;
                    }
                    O[i] = (I[i] + R) % 256;
                    R_prev = R;
                }

                vector<int> freq(256, 0);
                for (int i = 0; i < N; i++) {
                    freq[O[i]]++;
                }

                double entropy = 0.0;
                for (int count : freq) {
                    if (count > 0) {
                        double p = static_cast<double>(count) / N;
                        entropy -= p * log(p);
                    }
                }
                if (entropy < bestEntropy - 1e-9 ||
                    (abs(entropy - bestEntropy) < 1e-9 && (S < bestS || (S == bestS && (A < bestA || (A == bestA && C < bestC)))))) {
                    bestEntropy = entropy;
                    bestS = S;
                    bestA = A;
                    bestC = C;
                }
            }
        }
    }

    cout << bestS << " " << bestA << " " << bestC;
    return 0;
}
