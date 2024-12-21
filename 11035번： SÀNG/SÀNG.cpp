#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;

    while (true) {
        if (!(cin >> N >> K)) break;

        vector<bool> crossed(N + 1, false);
        int countCrossed = 0;
        int answer = 0;

        for (int i = 2; i <= N; i++) {
            if (!crossed[i]) {
                crossed[i] = true;
                countCrossed++;
                if (countCrossed == K) {
                    answer = i;
                    break;
                }

                for (int j = 2 * i; j <= N; j += i) {
                    if (!crossed[j]) {
                        crossed[j] = true;
                        countCrossed++;
                        if (countCrossed == K) {
                            answer = j;
                            break;
                        }
                    }
                }

                if (countCrossed == K) break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}