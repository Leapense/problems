#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    if (N <= 9) {
        cout << 1;
        return 0;
    }

    long long candidate = (N + 8) / 9;
    if (candidate % 2 == 0 && (N % 2 == 1)) {
        candidate++;
    }
    cout << candidate;
    return 0;
}
