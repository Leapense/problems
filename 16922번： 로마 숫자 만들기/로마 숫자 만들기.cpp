#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_set<int> sums;

    for (int i = 0; i <= N; i++) {
        for (int v = 0; v <= N - i; v++) {
            for (int x = 0; x <= N - i - v; x++) {
                int l = N - i - v - x;
                int sum = 1 * i + 5 * v + 10 * x + 50 * l;

                sums.insert(sum);
            }
        }
    }

    cout << sums.size() << "\n";

    return 0;
}