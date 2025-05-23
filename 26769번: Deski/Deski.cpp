#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N;
    cin >> N;

    if (N < 4) {
        cout << "0\n";
        return 0;
    }

    vector<int> L(N);
    ll max_L = 0;

    for (auto &x : L) {
        cin >> x;
        if (x > max_L) max_L = x;
    }

    ll low = 1, high = max_L, result = 0;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll count = 0;

        for (auto x : L) {
            if(x >= mid) count++;
            if(count >= 4) break;
        }

        if (count >= 4) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (result >= 1) {
        cout << result * result << "\n";
    } else {
        cout << "0\n";
    }

    return 0;
}