#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> t(N);
    for (auto &x : t) cin >> x;

    sort(t.begin(), t.end());
    ll left = t.back();
    ll right = t.back() * 2;

    auto possible = [&](ll M) -> bool {
        int start = 0, end = N - 1;
        int cnt = 0;
        while (start <= end) {
            if (t[start] + t[end] <= M) {
                start++;
            }
            end--;
            cnt++;
        }
        return cnt <= (N + 1) / 2;
    };

    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (possible(mid)) right = mid;
        else left = mid + 1;
    }

    cout << left << "\n";
    return 0;
}