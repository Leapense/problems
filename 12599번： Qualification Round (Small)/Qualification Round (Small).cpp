#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int P, C;
        cin >> P >> C;
        vector<int> S(P);
        for (int i = 0; i < P; ++i) {
            cin >> S[i];
        }
        sort(S.begin(), S.end());
        int sum_S = 0;
        for (int s : S) {
            sum_S += s;
        }
        int k = P - C + 1;
        int sum_min = 0;
        for (int i = 0; i < k; ++i) {
            sum_min += S[i];
        }
        int X = min(sum_S / C, sum_min);
        cout << "Case #" << t << ": " << X << endl;
    }
    return 0;
}