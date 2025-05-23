#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll res = N * (N + 2) * (2 * N + 1) / 8;
    cout << res << "\n";

    return 0;
}