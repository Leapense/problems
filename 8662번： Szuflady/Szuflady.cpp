#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<long long> a(n);

    for (auto &x : a) cin >> x;

    long long prev = a[n-1];
    int push_count = 0;

    for (int i = n - 2; i >= 0; i--) {
        long long current = min(a[i], prev - 1);
        if (current < 1) {
            cout << -1;
            return 0;
        }
        if (current < a[i]) {
            push_count++;
        }
        prev = current;
    }
    cout << push_count;

    return 0;
}