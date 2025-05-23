#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> p(n);

    for (auto &x : p) cin >> x;

    vector<long long> a(n, 0);
    long long s0 = 0;
    bool valid = true;

    for (int i = 0; i < n; i++) {
        long long s1;
        if (p[i] != -1) {
            if (p[i] < s0 + m) {
                valid = false;
                break;
            }
            if (i < n - 1 && p[i + 1] != -1) {
                if (p[i] > p[i + 1] - m) {
                    valid = false;
                    break;
                }
            }
            s1 = p[i];
        } else {
            if (i < n - 1 && p[i + 1] != -1) {
                long long s_max = p[i + 1] - m;
                long long s_min = s0 + m;
                if (s_min > s_max) {
                    valid = false;
                    break;
                }
                s1 = s_min;
            } else {
                s1 = s0 + m;
            }
        }
        a[i] = s1 - s0;
        s0 = s1;
    }

    if (valid) {
        for (int i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? " " : "\n");
    } else {
        cout << "-1\n";
    }

    return 0;
}