#include "main.h"

void solve(std::istream &in, std::ostream &out) {
    int N;
    in >> N;

    std::vector<int> I(N);
    for (int i = 0; i < N; i++) {
        in >> I[i];
    }

    double bestEntropy = std::numeric_limits<double>::max();
    int bestS = 0, bestA = 0, bestC = 0;

    for (int S = 0; S < 16; S++) {
        for (int A = 0; A < 16; A++) {
            for (int C = 0; C < 16; C++) {
                std::vector<int> O(N);
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

                std::vector<int> freq(256, 0);
                for (int i = 0; i < N; i++) {
                    freq[O[i]]++;
                }

                double entropy = 0.0;
                for (int count : freq) {
                    if (count > 0) {
                        double p = static_cast<double>(count) / N;
                        entropy -= p * std::log(p);
                    }
                }

                if (entropy < bestEntropy - 1e-9 || (std::abs(entropy - bestEntropy) < 1e-9 && (S < bestS || (S == bestS && (A < bestA || (A == bestA && C < bestC)))))) {
                    bestEntropy = entropy;
                    bestS = S;
                    bestA = A;
                    bestC = C;
                } 
            }
        }
    }

    out << bestS << " " << bestA << " " << bestC;
}

#ifndef UNIT_TESTS
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
