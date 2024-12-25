#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        double F;
        cin >> N >> F;
        string s;
        cin >> s;

        vector<int> binary_sequence(N);
        for (int i = 0; i < N; i++) {
            binary_sequence[i] = s[i] - '0';
        }

        vector<int> prefix(N + 1, 0);
        for (int i = 1; i <= N; i++)
    }
}