#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N = 8;
        vector<int> skills(N);

        for (int i = 0; i < N; ++i) {
            cin >> skills[i];
        }

        int min_diff = INT_MAX;

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    for (int l = k + 1; l < N; ++l) {
                        int sumA = skills[i] + skills[j] + skills[k] + skills[l];
                        int sumB = 0;

                        for (int m = 0; m < N; ++m) {
                            if (m != i && m != j && m != k && m != l) {
                                sumB += skills[m];
                            }
                        }

                        int diff = abs(sumA - sumB);
                        if (diff < min_diff) {
                            min_diff = diff;
                        }
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << min_diff << endl;
    }

    return 0;
}