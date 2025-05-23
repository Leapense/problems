#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, X;
        cin >> N >> X;
        vector<int> S(N);

        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }

        sort(S.begin(), S.end());
        int left = 0;
        int right = N - 1;
        int discs = 0;

        while (left <= right) {
            if (S[left] + S[right] <= X) {
                ++left;
            }
            --right;
            ++discs;
        }

        cout << "Case #" << t << ": " << discs << endl;
    }

    return 0;
}