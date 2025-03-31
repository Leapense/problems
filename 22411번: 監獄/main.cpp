#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;

    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = ans + (ans / (k - 1)) + 1;
    }

    cout << ans << "\n";
    return 0;
}
