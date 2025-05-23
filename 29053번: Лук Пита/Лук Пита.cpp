#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long L = LLONG_MIN, R = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long xi, di;
        cin >> xi >> di;
        long long left = xi - di;
        long long right = xi + di;
        L = max(L, left);
        R = min(R, right);
    }
    if (L > R) {
        cout << -1 << endl;
    } else {
        cout << R << endl;
    }
    return 0;
}