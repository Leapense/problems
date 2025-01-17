#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> B(N, 0);
    vector<int> T(N, 0);

    for (int i = 0; i < N; ++i) {
        int left = 0, right = N - 1;
        int count = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == i) {
                B[i] = count;
                break;
            }
            if (i < mid) {
                count += 1;
                right = mid - 1;
            } else {
                count += 1;
                left = mid + 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        int left = 0, right = N - 1;
        int count = 0;

        while (left <= right) {
            int delta = (right - left) / 3;
            int left_third = left + delta;
            int right_third = right - delta;

            if (left_third == i) {
                T[i] = count;
                break;
            }
            if (right_third == i) {
                T[i] = count + 1;
                break;
            }

            count += 2;

            if (i < left_third) {
                right = left_third - 1;
            } else if (i < right_third) {
                left = left_third + 1;
                right = right_third - 1;
            } else {
                left = right_third + 1;
            }
        }
    }

    int less = 0, equal = 0, greater = 0;

    for (int i = 0; i < N; ++i) {
        if (B[i] < T[i]) less += 1;
        else if (B[i] == T[i]) equal += 1;
        else greater += 1;
    }

    cout << less << "\n" << equal << "\n" << greater;

    return 0;
}