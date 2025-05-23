#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> cows(12);
    for (int &x : cows) {
        cin >> x;
    }

    sort(cows.begin(), cows.end());

    int min_diff = INT32_MAX;

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 11; j++) {
            for (int k = j + 1; k < 12; k++) {
                int first_sum = cows[i] + cows[j] + cows[k];

                int rem1[9];
                int idx1 = 0;
                for (int x = 0; x < 12; x++) {
                    if (x != i && x != j && x != k) {
                        rem1[idx1++] = x;
                    }
                }

                for (int a = 0; a < 7; a++) {
                    for (int b = a + 1; b < 8; b++) {
                        for (int c = b + 1; c < 9; c++) {
                            int second_sum = cows[rem1[a]] + cows[rem1[b]] + cows[rem1[c]];
                            int rem2[6];
                            int idx2 = 0;
                            for (int y = 0; y < 9; y++) {
                                if (y != a && y != b && y != c) {
                                    rem2[idx2++] = y;
                                }
                            }

                            int sum_remaining2 = 0;
                            for (int g = 0; g < 6; g++) {
                                sum_remaining2 += cows[rem1[rem2[g]]];
                            }

                            for (int d = 0; d < 4; d++) {
                                for (int e = d + 1; e < 5; e++) {
                                    for (int f = e + 1; f < 6; f++) {
                                        int third_sum = cows[rem1[rem2[d]]] + cows[rem1[rem2[e]]] + cows[rem1[rem2[f]]];

                                        int fourth_sum = sum_remaining2 - third_sum;
                                        int current_max = max({first_sum, second_sum, third_sum, fourth_sum});
                                        int current_min = min({first_sum, second_sum, third_sum, fourth_sum});

                                        int diff = current_max - current_min;

                                        if (diff < min_diff) {
                                            min_diff = diff;

                                            if (min_diff == 0) {
                                                cout << min_diff;
                                                return 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << min_diff;

    return 0;
}