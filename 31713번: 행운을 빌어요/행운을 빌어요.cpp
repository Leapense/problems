#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int A, B;
        cin >> A >> B;

        int N_min = max(A, (B + 3) / 4);
        int N_max = A + (B + 2) / 3;

        int min_sum = INT32_MAX;

        for (int N = N_min; N <= N_max; N++) {
            int X = max(0, N - A);
            int Y = max(0, 3 * N - B);
            int sum_add = X + Y;
            if (sum_add < min_sum) {
                min_sum = sum_add;
            }
        }

        if (A == 0 && B == 0) {
            min_sum = 0;
        }

        cout << min_sum << "\n";
    }

    return 0;
}