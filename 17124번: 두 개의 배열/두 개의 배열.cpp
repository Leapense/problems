#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> results;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> A(n), B(m);

        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];

        sort(B.begin(), B.end());
        long long total_sum = 0;

        for (int a : A) {
            auto pos = lower_bound(B.begin(), B.end(), a);
            int closest = 1e9;
            if (pos != B.begin()) {
                int left_val = *(prev(pos));
                if (abs(a - left_val) < abs(a - closest) || (abs(a - left_val) == abs(a - closest) && left_val < closest)) {
                    closest = left_val;
                }
            }

            if (pos != B.end()) {
                int right_val = *pos;

                if (abs(a - right_val) < abs(a - closest) || (abs(a - right_val) == abs(a - closest) && right_val < closest)) {
                    closest = right_val;
                }
            }

            total_sum += closest;
        }
        results.push_back(total_sum);
    }

    for (long long result : results) {
        cout << result << "\n";
    }

    return 0;
}