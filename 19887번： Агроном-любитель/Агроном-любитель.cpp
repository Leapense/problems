#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    int left = 0;
    int max_len = 1;
    int max_l = 0, max_r = 0;

    for (int right = 0; right < n; right++) {
        if (right >= 2 and a[right] == a[right - 1] and a[right] == a[right - 2]) {
            left = right - 1;
        }

        if (right - left + 1 > max_len) {
            max_len = right - left + 1;
            max_l = left;
            max_r = right;
        }
    }

    cout << (max_l + 1) << " " << (max_r + 1);

    return 0;
}