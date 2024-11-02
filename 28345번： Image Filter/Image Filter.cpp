#include <bits/stdc++.h>
using namespace std;

int compute_predict(int filter, int A, int B, int C) {
    switch(filter) {
        case 0:
            return 0;
        case 1:
            return A;
        case 2:
            return B;
        case 3:
            return (A + B) / 2;
        case 4:
            return A + B - C;
        default:
            return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C;

        cin >> R >> C;

        vector<vector<int>> H(R, vector<int>(C, 0));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> H[i][j];
            }
        }

        vector<vector<pair<int, int>>> result(R, vector<pair<int, int>>(C, {0,0}));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int A = (j > 0) ? H[i][j-1] : 0;
                int B = (i > 0) ? H[i-1][j] : 0;
                int C_val = (i > 0 && j > 0) ? H[i-1][j-1] : 0;

                int H_val = H[i][j];
                int min_abs_diff = INT32_MAX;
                int chosen_filter = 0;
                int chosen_diff = 0;

                for (int filter = 0; filter <= 4; ++filter) {
                    int P = compute_predict(filter, A, B, C_val);

                    int diff = H_val - P;
                    int abs_diff = abs(diff);

                    if (abs_diff < min_abs_diff) {
                        min_abs_diff = abs_diff;
                        chosen_filter = filter;
                        chosen_diff = diff;
                    } else if (abs_diff == min_abs_diff) {
                        if(filter < chosen_filter) {
                            chosen_filter = filter;
                            chosen_diff = diff;
                        }
                    }
                }

                result[i][j] = {chosen_filter, chosen_diff};
            }
        }

        for (int i = 0; i < R; ++i) {
            string line = "";
            for (int j = 0; j < C; ++j) {
                line += to_string(result[i][j].first) + " " + to_string(result[i][j].second);

                if (j != C - 1) {
                    line += " ";
                }
            }

            cout << line << "\n";
        }
    }

    return 0;
}