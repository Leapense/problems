#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int N;
    cin >> N;

    vector<ll> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << "YES\n";
        cout << A[0] << "\n" << 0 << "\n";
        return 0;
    }

    ll d = A[1] - A[0];

    bool is_arithmetic = true;

    for (int i = 2; i < N; ++i) {
        if (A[i] - A[i - 1] != d) {
            is_arithmetic = false;
            break;
        }
    }

    if (!is_arithmetic) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (int i = 0; i < N; ++i) {
        cout << A[0] << ' ';
    }

    cout << '\n';

    for (int i = 0; i < N; ++i) {
        cout << (A[i] - A[0]) << ' ';
    }

    cout << '\n';

    return 0;
}