#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc < 5 || argc > 6) {
        quitf(_fail, "Usage: %s minN maxN minC maxC [seed]", argv[0]);
    }

    int minN = atoi(argv[1]);
    int maxN = atoi(argv[2]);
    long long minC = atoll(argv[3]);
    long long maxC = atoll(argv[4]);

    ensure(minN >= 2 && minN <= maxN);
    ensure(minC > 0 && minC <= maxC);

    if (argc == 6) rnd.setSeed(atoi(argv[5]));

    int N = rnd.next(minN, maxN);
    cout << N << '\n';

    vector<long long> small(N + 1), big(N + 1);

    for (int i = 1; i <= N - 1; ++i) {
        small[i] = rnd.next(minC, maxC);
        big[i] = rnd.next(minC, maxC);
    }

    long long K = rnd.next(minC, maxC);

    if (rnd.next(0, 9) == 0) {
        int variant = rnd.next(0, 4);
        switch (variant) {
            case 0:
                for (int i = 1; i <= N - 1; ++i) {
                    small[i] = maxC - i;
                    big[i] = maxC - 1LL * i * i;
                }
                K = minC;
                break;
            case 1:
                for (int i = 1; i <= N - 1; ++i) {
                    small[i] = maxC - i;
                    big[i] = maxC - 1LL * i * i;
                }
                K = minC;
                break;
            case 2:
                for (int i = 1; i <= N - 1; ++i) {
                    small[i] = big[i] = minC;
                }
                for (int t = 0; t < N / 10; ++t) {
                    int idx = rnd.next(1, N - 1);
                    small[idx] = big[idx] = maxC;
                }
                K = rnd.next(minC, maxC);
                break;
            case 3:
                for (int i = 1; i <= N - 1; ++i) {
                    small[i] = rnd.next(minC, maxC);
                    big[i] = max<long long>(minC, small[i] + rnd.next(-1, 1));
                }
                K = rnd.next(minC, maxC);
                break;
            case 4:
                N = 2;
                cout << "\b" << N << "\n";
                small.assign(3, minC);
                big.assign(3, minC);
                K = minC;
                break;
        }
    }

    for (int i = 1; i <= N - 1; ++i) {
        cout << small[i] << " " << big[i] << "\n";
    }

    cout << K << "\n";
    return 0;
}