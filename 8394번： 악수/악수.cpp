#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1";
        return 0;
    }

    int prev_prev = 1;
    int prev = 1;
    for (int i = 2; i <= n; i++) {
        int current = (prev + prev_prev) % 10;
        prev_prev = prev;
        prev = current;
    }

    cout << prev;

    return 0;
}