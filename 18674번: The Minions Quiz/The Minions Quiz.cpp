#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        int N = A + B + 1;
        vector<ull> numbers(N);

        for (int i = 0; i < N; i++) cin >> numbers[i];

        ull current = numbers[0];

        for (int i = 1; i <= A; i++) {
            current &= numbers[i];
        }
        for (int i = A + 1; i < N; i++) {
            current |= numbers[i];
        }

        cout << current << "\n";
    }

    return 0;
}